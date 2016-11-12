#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool is_sorted(const vector<char>& vec) {

	for (int i = 1, n = vec.size(); i < n; i++) {
		if (vec[i-1] > vec[i]) return false;
		// returns false if an element is smaller than one to its left
	}

	return true;
}

void shuffle(vector<char>& vec) {
	int i,n, tmp, rand_idx;

	for(i = 0, n = vec.size(); i < n; i++) {

		tmp = vec[i]; // store temporarily

		rand_idx = rand() % n; // pick a random index in the vector/array

		// swap each element in vector/array with another one that is chosen randomly
		vec[i] = vec[rand_idx];
		vec[rand_idx] = tmp;
	}
}

void bogosort(vector<char>& vec) {
	while( !is_sorted(vec) ) shuffle(vec);
}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) bogosort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}
