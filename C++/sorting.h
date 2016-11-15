#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <iterator>

namespace Sorting {

	template<typename T>
	using Iterator = typename std::vector<T>::iterator;

/*
    ------------------
	    Prototypes
	------------------
*/

	template<typename T>
	void bubblesort(Iterator<T> begin, Iterator<T> end);

	template<typename T>
	void insertionsort(Iterator<T> begin, Iterator<T> end);

	template<typename T>
	void selectionsort(Iterator<T> begin, Iterator<T> end);

	template<typename T>
	void mergesort(Iterator<T> begin, Iterator<T> end);

	template<typename T>
	void quicksort(Iterator<T> begin, Iterator<T> end);

/* and now some overloads... */

	template<typename T>
	void bubblesort(std::vector<T>& vec);

	template<typename T>
	void insertionsort(std::vector<T>& vec);

	template<typename T>
	void selectionsort(std::vector<T>& vec);

	template<typename T>
	void mergesort(std::vector<T>& vec);

	template<typename T>
	void quicksort(std::vector<T>& vec);

/*
    -----------------------
	    Implementations
	-----------------------
*/

	template<typename T>
	void bubblesort(Iterator<T> begin, Iterator<T> end) {
		bool c = true;
		while (c && !(c = false))
			for (Iterator<T> inner_it = begin ; inner_it != end-1 ; inner_it++)
				if ( *inner_it > *(inner_it+1) && (c = true))
					std::swap(*inner_it, *(inner_it+1));
	}

	template<typename T>
	void bubblesort(std::vector<T>& vec) {
		bubblesort<T>(vec.begin(), vec.end());
	}

	template<typename T>
	void insertionsort(Iterator<T> begin, Iterator<T> end) {
		for (Iterator<T> inner_it = begin+1 ; inner_it != end ; inner_it++) {
			if ( *inner_it < *(inner_it-1) ) {

				T hold = *inner_it;
				Iterator<T> copy = inner_it;

				while (copy != begin && *(copy-1) > hold) {
					*copy = *(copy-1);
					copy--;
				}

				*copy = hold;
			} /* end if */
		} /* end for */
	}

	template<typename T>
	void insertionsort(std::vector<T>& vec) {
		insertionsort<T>(vec.begin(), vec.end());
	}

	template<typename T>
	void selectionsort(Iterator<T> begin, Iterator<T> end) {
		for (Iterator<T> it = begin, min_pos ; it != end ; it++) {
			min_pos = it;

			for (Iterator<T> inner_it = it+1 ; inner_it != end ; inner_it++)
				min_pos = *inner_it < *min_pos ? inner_it : min_pos;

			if (min_pos != it)
				std::swap(*it, *min_pos);
		}
	}

	template<typename T>
	void selectionsort(std::vector<T>& vec) {
		selectionsort<T>(vec.begin(), vec.end());
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
	    vec.clear();

	    mergesort(left); mergesort(right);

	    while(!left.empty() && !right.empty()) {
	        if (left.front() < right.front()) {

	            vec.push_back(left.front());
	            left.erase(left.begin());
	        } else {

	            vec.push_back(right.front());
	            right.erase(right.begin());
	        }
	    }

	    if (!left.empty()) {
	        vec.insert(vec.end(), left.begin(), left.end());
	    } else if (!right.empty()) {
	        vec.insert(vec.end(), right.begin(), right.end());
	    }
	}

	template<typename T>
	void mergesort(Iterator<T> begin, Iterator<T> end) {
		std::vector<T> vec(begin,end);
		mergesort<T>(vec);
		for (auto& e : vec)
			*(begin++) = e;
	}

	template<typename T>
	void quicksort(Iterator<T> begin, Iterator<T> end) {
	    if (std::distance(begin,end) <= 1) return;

	    Iterator<T> a, b;

	    T pivot = *(end - 1);

	    a = begin; b = end - 1;

	    while(b > a) {
	        if ( *(b-1) > pivot) {
	            *b = *(b-1);
				b--;
	        } else {
            	std::swap(*(b-1), *a++);
	        }
	    }

	    *b = pivot;

	    quicksort<T>(begin, b);
	    quicksort<T>(b + 1, end);
	}

	template<typename T>
	void quicksort(std::vector<T>& vec) {
		quicksort<T>(vec.begin(), vec.end());
	}
};

#endif
