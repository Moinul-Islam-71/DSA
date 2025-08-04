#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls(10, 3);
    
    cout << "size of list: " << ls.size() << endl;
    
    cout << "list 1: ";
    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;
    
    list<int> ls2(ls.begin(), ls.end());
    
    cout << "list 2: ";
    for(auto it: ls2) {
        cout << it << " ";
    }

    cout << endl;
    
    int arr[] = {10, 20, 30};
    list<int> ls3(arr, arr+3);
    
    cout << "list 3: ";
    for(auto it: ls3) {
        cout << it << " ";
    }

    cout << endl;

    vector<int> v = {12, 23, 45};
    list<int> ls4(v.begin(), v.end());
    
    cout << "list 4: ";
    for(auto it: ls4) {
        cout << it << " ";
    }

    return 0;
}