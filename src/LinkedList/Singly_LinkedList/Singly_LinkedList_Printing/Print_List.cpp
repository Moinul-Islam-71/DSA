#include <bits/stdc++.h>
using namespace std;

int sz = 0;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head) {
    Node* tmp = head;

    while(tmp != NULL) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}
