#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
void swap(vector<char>::iterator a, vector<char>::iterator b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
bool sorted(vector<char>::iterator begin, vector<char>::iterator end) {
	for (auto i = begin; i != end - 1; i++) {
		if (*(i + 1) < *i) return false;
	}

	return true;
}
void insertionsort(vector<char>::iterator begin, vector<char>::iterator end) {

	while (!sorted(begin, end)) {
		for (auto i = begin + 1; i != end; i++) {

			if (*(i - 1) > *i) {
				char hold = *i;
				auto pos = i;

				while (pos > begin && *(pos - 1) > hold) {

					*pos = *(pos - 1);
					pos--;
				}

				*pos = hold;
			}
		}
	}
}
void quicksort(vector<char>::iterator begin, vector<char>::iterator end) {
	/*
	 * Recursion Terminating Conditions:
	*/
	if (distance(begin,end) <= 1) return;
	if (distance(begin, end) <= 10) {
		insertionsort(begin, end);
		return;
	}

	vector<char>::iterator a, b;

    char pivot = *(end - 1);

    a = begin; b = end - 1;

    while(b > a) {
        if ( *(b-1) > pivot) {
            *b = *(b-1);
            b--;
        } else {
            swap(b-1, a);
            a++;
        }
    }

    *b = pivot;

    quicksort(begin, b);
    quicksort(b + 1, end);
}


int main() {

	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	quicksort(vec.begin(), vec.end());

	string str(vec.begin(), vec.end());

	cout << str << endl;

	return 0;
}
