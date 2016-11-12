#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void bubblesort(vector<char>& vec) {
	int n = vec.size();
	char temp;

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

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) bubblesort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}
