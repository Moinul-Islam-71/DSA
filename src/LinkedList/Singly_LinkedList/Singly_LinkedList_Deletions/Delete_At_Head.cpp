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

void delete_at_head(Node* &head, Node* &tail) {

    if(head == NULL)return;

    Node* del_node = head;
    head = head->next;

    //If head becomes NULL then tail should also be NULL
    if (head == NULL) {
        tail = NULL;
    }

    delete del_node;
    sz--;

}
