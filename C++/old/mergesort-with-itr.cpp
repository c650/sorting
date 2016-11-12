/*
	not yet working.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>

template<typename T>
void mergesort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
	int n = std::distance(begin,end);

	if (n <= 1) {
		return;
	} else if (n == 2) {
		if (*begin > *(begin+1)) {
			std::swap(*begin, *(begin+1));
		}

		return;
	}

	mergesort<T>(begin, begin + n / 2);
	mergesort<T>(begin + n / 2, end);

	typename std::vector<T>::iterator left, right, mid, itr;
	left = itr = begin;
	right = mid = begin + n / 2;

	while(left != mid && right != end && itr != end) {
		if (*left <= *right) {
			*itr = *left++;
		} else {
			*itr = *right++;
		}
	}

	if (left != mid) {
		while (itr != end && left != mid) {

		}
	} else if (right != end) {
		while (itr != end && right != end) {

		}
	}
}

int main() {
	std::cout << "give me a string" << std::endl;
	std::string s; std::getline(std::cin, s);

	std::vector<char> vec(s.begin(), s.end());

	mergesort<char>(vec.begin(), vec.end());

	std::string str(vec.begin(), vec.end());

	std::cout << str << std::endl;
	return 0;
}
