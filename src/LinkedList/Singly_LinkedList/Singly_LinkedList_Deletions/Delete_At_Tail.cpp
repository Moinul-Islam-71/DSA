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

void delete_at_tail(Node* &head, Node* &tail) {

    if(head == NULL) return;

    Node* del_node = tail;

    Node* tmp = head;

    if(head->next == NULL) {
        delete del_node;
        sz--;
        head = NULL;
        tail = NULL;
        return;
    }

    
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = NULL;
    tail = tmp;


    delete del_node;
    sz--;

}
