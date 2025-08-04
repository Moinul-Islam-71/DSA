#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> myList(10); // Initialize a list with 10 elements

    cout << "Size of the list: " << myList.size() << endl;

    if(!myList.empty()) {
        for(auto it: myList) {
            cout << it << " "; // Print each element in the list
        }
    }

    else {
        cout << "The list is empty" << endl;
    }

    return 0;
}