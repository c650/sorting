#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
 
using namespace std;

void swap(vector<char>::iterator a, vector<char>::iterator b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void quicksort(vector<char>::iterator begin, vector<char>::iterator end) {
    if (distance(begin,end) <= 1) return;
 
    vector<char>::iterator a, b;
 
    char pivot = *(end - 1);

    a = begin; b = end - 1;

    while(b > a) {
        if ( *(b-1) > pivot) {
            *b = *(b-1);
            b--;
        } else {
            swap(b-1, a);
            a++;
        }
    }

    *b = pivot;

    quicksort(begin, b);
    quicksort(b + 1, end);
}
 
 
int main() {
 
    cout << "give me a string" << endl;
    string s; getline(cin, s);
 
    vector<char> vec(s.begin(), s.end());
 
    quicksort(vec.begin(), vec.end());
 
    string str(vec.begin(), vec.end());
 
    cout << str << endl;
    return 0;
}