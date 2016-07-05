#include <iostream>
#include <string>
#include <cstdlib>

bool sorted(char* arr, int begin, int end) {
	for (auto i = begin; i < end - 1; i++) {
		if (arr[i+1] < arr[i]) return false;
	}

	return true;
}
void insertionsort(char* arr, int begin, int end) {

	while (!sorted(arr, begin, end)) {
		for (auto i = begin + 1; i != end; i++) {

			if (arr[i-1] > arr[i]) {
				char hold = arr[i];
				auto pos = i;

				while (pos > begin && arr[pos-1] > hold) {
					
					arr[pos] = arr[pos-1];
					pos--;
				}

				arr[pos] = hold;
			}
		}
	}
}
void quicksort(char* arr, int begin, int end) {
	/*
	 * Recursion Terminating Conditions:
	*/
	if (end - begin <= 1) return;
	if (end - begin <= 10) {
		insertionsort(arr, begin, end);
		return;
	}

	int a,b;
 
    char pivot = arr[end-1];

    a = begin; b = end - 1;

    while(b > a) {
        if ( arr[b-1] > pivot ) {
            arr[b] = arr[b-1];
            b--;
        } else {
        	// swap a and b-1
            arr[a] = arr[a] + arr[b-1];
            arr[b-1] = arr[a] - arr[b-1];
            arr[a] = arr[a] - arr[b-1];

            a++;
        }
    }

    arr[b] = pivot;

    quicksort(arr, begin, b);
    quicksort(arr, b + 1, end);
}


int main(int argc, char** argv) {

	if (argc != 3) {
		std::cout << "Usage: ./program <path to file> <length to read>" << std::endl;
		exit(1);
	}

	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		std::cout << "[*] Error opening file" << std::endl;
		exit(2);
	}

	int n = atoi(argv[2]);
	char* arr = new char[n];

	if (arr == nullptr) {
		std::cout << "[*] Cannot allocate memory for array" << std::endl;
		fclose (fp);
		exit(3);
	}

	for (int i = 0; i < n; i++) {
		if ((arr[i] = fgetc(fp)) == EOF) {
			std::cout << "[*] File EOF caught at " << i << std::endl;
			std::cout << "[*] Reassigning n to " << i+1 << std::endl;
			n = i+1;
			break;
		}
	}

	std::cout << "[*] Input received." << std::endl;

	quicksort(arr, 0, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;

	delete[] arr;
	fclose(fp);

	return 0;
}