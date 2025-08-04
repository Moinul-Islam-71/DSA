#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls({12, 23, 45});

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    ls.resize(2);

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    ls.resize(5);

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    cout << ls.size() << endl;


    ls.resize(7, 100);

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;


    return 0;
}