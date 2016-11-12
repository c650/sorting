#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <iterator>

namespace Sorting {

	template<typename T>
	bool sorted(std::vector<T>& vec);

	template<typename T>
	void bubblesort(std::vector<T>& vec) {
		int n = vec.size();
		T temp;

		for (int i = 0; i < n-1; i++) {

			for (int j = 0; j < n-1; j++) {
				if (vec[j+1] < vec[j]) {

					temp = vec[j+1];
					vec[j+1] = vec[j];
					vec[j] = temp;

				}
			}
		}
	}

	template<typename T>
	void insertionsort(std::vector<T>& vec) {
		int n = vec.size();
		while (!sorted(vec)) {
			for (int i = 1; i < n; i++) {
				if (vec[i-1] > vec[i]) {
					int hold = vec[i];

					int pos = i;
					while (pos > 0 && vec[pos - 1] > hold) {

						vec[pos] = vec[pos - 1];
						pos--;
					}
					vec[pos] = hold;
				}
			}
		}
	}

	template<typename T>
	void selectionsort(std::vector<T>& vec) {
		int n = vec.size();

		for (int i = 0; i < n; i++) {

			int min_pos = i;

			for (int j = i + 1; j < n; j++) {
				if (vec[j] < vec[min_pos]) {
					min_pos = j;
				}
			}
			if (min_pos != i) {
				int tmp = vec[i];
				vec[i] = vec[min_pos];
				vec[min_pos] = tmp;
			}
		}
	}

	template<typename T>
	void mergesort(std::vector<T>& vec) {
	    int n = vec.size();

	    // recursion terminator
	    if (n <= 1) return;
	    else if (n == 2) {
	        if (vec[0] > vec[1]) {

	            std::swap(vec[0],vec[1]);

	        }

	        return;
	    }

	    std::vector<T> left(vec.begin(), vec.begin() + n / 2);
	    std::vector<T> right(vec.begin() + n / 2, vec.end());
	    vec.clear(); // because we have copied the values to the partitions (left and right)

	    mergesort(left); mergesort(right);

	    int itr = 0;

	    while(!left.empty() && !right.empty() && itr < n) {
	        if (left[0] < right[0]) {

	            vec.push_back(left.front());

	            left.erase(left.begin());
	        } else {

	            vec.push_back(right.front());

	            right.erase(right.begin());
	        }

	        itr++;
	    }

	    if (!left.empty()) {
	        vec.insert(vec.end(), left.begin(), left.end());
	    } else if (!right.empty()) {
	        vec.insert(vec.end(), right.begin(), right.end());
	    }

	}


	template<typename T>
	void quicksort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
	    if (std::distance(begin,end) <= 1) return;

	    typename std::vector<T>::iterator a, b;

	    T pivot = *(end - 1);

	    a = begin; b = end - 1;

	    while(b > a) {
	        if ( *(b-1) > pivot) {
	            *b = *(b-1);
	            b--;
	        } else {
            	std::swap(*(b-1), *a);
	            a++;
	        }
	    }

	    *b = pivot;

	    quicksort<T>(begin, b);
	    quicksort<T>(b + 1, end);
	}

	template<typename T>
	bool sorted(std::vector<T>& vec) {
		for (int i = 1, n = vec.size(); i < n; i++) {
			if (vec[i] < vec[i-1]) return false;
		}

		return true;
	}
};

#endif
