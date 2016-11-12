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
// BELOW IS JUST INPUT, FEEL FREE TO OVERLOOK
int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) insertionsort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}
