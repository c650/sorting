#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


void quicksort(vector<char>& vec, const int pivot_point) {
	if (vec.size() <= 1) return;

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
