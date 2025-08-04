#include <bits/stdc++.h>
using namespace std;

//The functions that have used: erase, clear, swap, 

int main() {
    list<int> ls({12, 23, 34, 45, 56, 67});

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    ls.erase(next(ls.begin(), 2));

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    ls.erase(next(ls.begin(), 1), prev(ls.end(), 1));

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    ls.clear();

    cout << ls.size() << endl;

    list<int> ls2({1, 2, 3});
    list<int> ls3({4, 5, 6});

    ls2.swap(ls3);

    for(auto it: ls2) {
        cout << it << " ";
    }

    cout << endl;

    for(auto it: ls3) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
