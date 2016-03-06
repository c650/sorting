#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void bubblesort(vector<char>& vec) {
	int n = vec.size();

	// nest loops because O(n^2)
	// changes_made is an optimization that can reduce runtime in certain conditions
	bool changes_made = false;

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1; j++) {
			if (vec[j] > vec[j+1]) {

				// swap them
				char temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;

				// tell program to run thru vec at least once more
				changes_made = true;
			}
		}

		// optimization to exit loop if no changes made
		if (!changes_made) break;

		changes_made = false;
	}
}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) bubblesort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}