#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
 
using namespace std;
/* swap function */
void swap(vector<char>& vec, int a, int b) {
    char tmp = vec[a];
    vec[a] = vec[b];
    vec[b] = tmp;
}
/* heapsort */
void heapsort(vector<char>& vec) {
    make_heap(vec.begin(), vec.end()); // first things first: heapify

    int count = vec.size() - 1;

    swap(vec[0],vec[count]);

    while (count-- > 0) {
        // shift(vec, 0, count);
        make_heap(vec.begin(), vec.begin() + count);
        swap(vec[0],vec[count]);
    }
}
 
int main() {
 
    cout << "give me a string" << endl;
    string s; getline(cin, s);
 
    vector<char> vec(s.begin(), s.end());
 
    heapsort(vec);
 
    string str(vec.begin(), vec.end());
 
    cout << str << endl;
    return 0;
}