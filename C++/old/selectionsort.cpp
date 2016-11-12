#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void selectionsort(vector<char>& vec) {
	int n = vec.size();

	for (int i = 0; i < n; i++) {

		int min_pos = i; // assume first element is the smallest

		for (int j = i + 1; j < n; j++) {
			// update position of min element if we find a smaller one
			if (vec[j] < vec[min_pos]) {
				min_pos = j;
			}
		}

		// if the minimun is not at position i, we must swap
		if (min_pos != i) {
			int tmp = vec[i];
			vec[i] = vec[min_pos];
			vec[min_pos] = tmp;
		}
	}
}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) selectionsort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}
