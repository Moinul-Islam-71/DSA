#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls({12, 23, 45, 56, 67, 78, 89, 90, 34});

    //Copying all elements from the list
    list<int> ls2 = ls;

    for(auto it: ls2) {
        cout << it << " ";
    }

    cout << endl;

    
    //Copying all elements except the first two and last two elements
    list<int> ls3(next(ls.begin(), 2), prev(ls.end(), 2));

    for(auto it: ls3) {
        cout << it << " ";
    }

    return 0;
}