#include <bits/stdc++.h>
using namespace std;


int main() {
    std::list<int> ls({12, 20, 23, 34, 20, 45, 20, 56, 20, 67});

    // Replace all occurrences of 20 with 100 with given range and value

    replace(ls.begin(), ls.end(), 20, 100); // Replaces all occurrences of 20 with 100

    ls.remove(100); // Removes all occurrences of 100

    for (int x : ls) {
        cout << x << " ";
    }

    cout << endl;

    // Sorting the list in ascending order
    // ls.sort();

    // Sorting the list in descending order
    ls.sort(greater<int>());

    for (int x : ls) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}