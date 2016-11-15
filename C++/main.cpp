#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include <time.h>

#include "sorting.h"

template<typename T>
static void pvec(std::vector<T>& v) {
	std::cout << "vec:\t";
	for (auto& a : v)
		std::cout << a << " ";
	std::cout << std::endl;
}

template<typename T>
static void shuf(std::vector<T>& v) {
	for (int i = v.size() - 1 ; i >= 0 ; i--)
		std::swap(v[i], v[rand() % v.size()]);
}

int main() {
	srand(time(NULL));

	std::vector<int> vec(10);
	for (auto& a : vec)
		a = rand() % vec.size();

	pvec(vec);

	std::sort( vec.begin() , vec.end() );
	pvec(vec);
	shuf(vec);

	Sorting::bubblesort<int>( vec );
	pvec(vec);
	shuf(vec);

	Sorting::insertionsort<int>( vec );
	pvec(vec);
	shuf(vec);

	Sorting::selectionsort<int>(vec);
	pvec(vec);
	shuf(vec);

	Sorting::quicksort<int>(vec);
	pvec(vec);
	shuf(vec);

	Sorting::mergesort<int>(vec);
	pvec(vec);

	return 0;
}
