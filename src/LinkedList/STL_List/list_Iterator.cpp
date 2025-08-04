#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls(10, 23);

    auto i = ls.begin();
    auto j = ls.end();

    cout << *i << endl;

    for (auto it = i; i != j; i++) {
        cout << *it << " ";
    }

    return 0;
}