#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls({12, 23, 34, 45});
    
    list<int> ls2;
    ls2.assign(ls.begin(), ls.end());

    for(auto it: ls2) {
        cout << it << " ";
    }

    cout << endl;

    list<int> ls3;
    ls3.assign(next(ls.begin(), 1), prev(ls.end(), 1));


    for(auto it: ls3) {
        cout << it << " ";
    }

    cout << endl;

    //inserting a single value at a specific position
    ls3.insert(next(ls3.begin(), 1), 99);

    // Displaying the list after insertion
    for(auto it: ls3) {
        cout << it << " ";
    }

    cout << endl;

    ls.insert(next(ls.begin(), 2), ls3.begin(), ls3.end());

    for(auto it: ls) {
        cout << it << " ";
    }

    cout << endl;

    //.......................................................................

    //but inserting a value at a specific position in vector                
    vector<int> vec({1, 2, 3, 4, 5, 6});

    //formula 1
    vec.insert(vec.begin()+3, 100);


    //formula 2
    vec.insert(next(vec.begin(), 2), 99); 

    // Displaying the vector after insertion
    for(auto it: vec) {
        cout << it << " ";
    }

    //.......................................................................


    return 0;
}