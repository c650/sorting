#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool sorted(vector<char>& vec) {
	for (int i = 1, n = vec.size(); i < n; i++) {
		if (vec[i] < vec[i-1]) return false;
	}

	return true;
}
void insertionsort(vector<char>& vec) {
	int n = vec.size();
	/* 
	* The first element in the array is treated as sorted,
	* so we go on to the second one, vec[1], which is why
	* the for loop starts at i = 1
	*/
	while (!sorted(vec)) {
		for (int i = 1; i < n; i++) {
			// if the element to the left bigger than the element we are looking at, vec[i]
			// we need to put vec[i] where it belongs.
			// and we do this by temporarily storing the value of vec[i] and then shifting
			// all the elements of the array/vec that are bigger than vec[i] to the right
			// until we arrive at vec[i]'s new, rightful place
			if (vec[i-1] > vec[i]) {
				int hold = vec[i]; // hold value

				int pos = i; // track positive to insert `hold`
				
				while (pos > 0 && vec[pos - 1] > hold) {
					
					vec[pos] = vec[pos - 1];
					pos--;

					// but, if our original vec[i] is bigger than
					// the element we shifted in the last iteration,
					// we can stop shifting
				}
				// now we can put the original vec[i] where it belongs by accessing
				// the pos variable which holds the position we want to INSERT the
				// original vec[i] into
				vec[pos] = hold;
			}
		}
	}
}
void quicksort(vector<char>& vec, const int pivot_point) {
	/*
	 * Recursion Terminating Conditions:
	*/
	if (vec.size() <= 1) return;
	
	if (vec.size() <= 10) {
		insertionsort(vec);
		return;
	}

	char pivot_char = vec[pivot_point];

	vector<char> left, right;

	for (int i = 0, n = vec.size(); i < n; i++) {
		if (i == pivot_point) continue;

		if (vec[i] < pivot_char) {
			left.push_back(vec[i]);
		} else {
			right.push_back(vec[i]);
		}
	}

	if (!left.empty()) quicksort(left, rand() % left.size());
	if (!right.empty()) quicksort(right, rand() % right.size());

	vec = left;
	vec.push_back(pivot_char);
	vec.insert(vec.end(), right.begin(), right.end());
}


int main() {

	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) quicksort(vec, rand() % vec.size());

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}