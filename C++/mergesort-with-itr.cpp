#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

void mergesort(vector<char>::iterator begin, vector<char>::iterator end) {
	int n = distance(begin,end);

	// recursion terminator
	if (n <= 1) return;

	else if (n == 2) {
		if (*begin > *(begin+1)) {

			char tmp = *begin;
			*begin = *(begin+1);
			*(begin+1) = tmp;
			
		}

		return;
	}

	mergesort(begin, begin + n / 2); mergesort(begin + n / 2, end);

	vector<char>::iterator left, right, mid, itr;
	left = itr = begin;
	right = mid = begin + n / 2;

	while(left != mid && right != end && itr != end) {
		if (*left <= *right) {
			*itr = *left;

			itr++; left++;
		} else {
			*itr = *right;

			itr++; right++;
		}
	}

	if (left != mid) {
		while (itr != end && left != mid) {
			*itr = *left;

			itr++; left++;
		}
	} else if (right != end) {
		while (itr != end && right != end) {
			*itr = *right;

			itr++; right++;
		}
	}

}

int main() {
	cout << "give me a string" << endl;
	string s; getline(cin, s);

	vector<char> vec(s.begin(), s.end());

	mergesort(vec.begin(), vec.end());

	string str(vec.begin(), vec.end());

	cout << str << endl;
	return 0;
}