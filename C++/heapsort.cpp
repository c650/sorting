#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
 
using namespace std;
/* HELPER FUNCTIONS FOR MANIPULATING LINEAR HEAP */
int get_left_child(int idx) {
    return idx * 2 + 1;
}

int get_right_child(int idx) {
    return idx * 2 + 2;
}

int get_parent(int idx) {
    return idx / 2 - 1;
}
/* END HELPERS FOR HEAP */
/* swap function */
void swap(vector<char>& vec, int a, int b) {
    char tmp = vec[a];
    vec[a] = vec[b];
    vec[b] = tmp;
}
void shift(vector<char>& vec, int a, int b) {
    int root = a;

    while(get_left_child(root) >= b) {
        int child = get_left_child(root);
        int swap_point = root;

        if (vec[child] > vec[swap_point]) { // if the left child is larger than root, prep for swap
            swap_point = child;
        }

        if (child + 1 >= b && vec[child+1] > vec[swap_point]) { // if the right child is bigger than prev chosen swap, make it swap
            swap_point = child + 1;
        }

        if (swap_point == root) return; // no need to swap if root bigger than children
        else {
            swap(vec, swap_point, root); // otherwise we need to swap
            root = swap_point; // now we gotta go down the heap to re-heap anything affected by that swap
        }
    }
}
/* heapsort */
void heapsort(vector<char>& vec) {
    make_heap(vec.begin(), vec.end()); // first things first: heapify

    int count = vec.size() - 1;

    swap(vec[0],vec[count]);

    while (count-- > 0) {
        shiftup(vec, 0, count);
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