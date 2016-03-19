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

	for (int j = 1; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (vec[i-1] > vec[i]) {
				int hold = vec[i]; // hold value

				int pos = i; // track positive to insert `hold`
				
				while ( pos > 0) {
					vec[pos] = vec[pos - 1];
					pos--;
					
					if (vec[pos + 1] <= hold) break;
				}

				vec[pos] = hold;
			}
		}
		if (sorted(vec)) break;
	}
}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) insertionsort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}