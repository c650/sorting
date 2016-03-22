#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void mergesort(vector<char>& vec) {
	int n = vec.size();

	// recursion terminator
	if (n <= 1) return;
	else if (n == 2) {
		if (vec[0] > vec[1]) {

			char tmp = vec[0];
			vec[0] = vec[1];
			vec[1] = tmp;
			
		}

		return;
	}

	vector<char> left(vec.begin(), vec.begin() + n / 2);
	vector<char> right(vec.begin() + n / 2, vec.end());
	vec.erase(vec.begin(), vec.end()); // because we have copied the values to the partitions (left and right)

	mergesort(left); mergesort(right);

	int itr = 0;
	
	while(!left.empty() && !right.empty() && itr < n) {
		if (left.front() < right.front()) {

			vec.push_back(left.front());

			left.erase(left.begin());
		} else {

			vec.push_back(right.front());
			
			right.erase(right.begin());
		}

		itr++;
	}
	
	if (!left.empty()) {
		vec.insert(vec.end(), left.begin(), left.end());
	} else if (!right.empty()) {
		vec.insert(vec.end(), right.begin(), right.end());
	}

}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	if (!vec.empty()) mergesort(vec);

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}