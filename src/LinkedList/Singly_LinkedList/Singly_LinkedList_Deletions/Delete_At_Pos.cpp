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

void delete_at_tail(Node* &head, Node* &tail) {

    if(head == NULL)return;

    Node* del_node = tail;

    Node* tmp = head;

    if(head->next == NULL) {
        delete del_node;
        head = NULL;
        tail = NULL;
        sz--;
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

void delete_at_pos(Node* &head, Node* &tail, int pos) {

    if(pos > sz || pos < 1) {
        return;
    }

    if(pos == 1) {
        delete_at_head(head, tail);
        return;
    }

    if(pos == sz) {
        delete_at_tail(head, tail);
        return;
    }
    
    Node* tmp = head;

    //Traverse to the node just before the deletion point
    for(int i = 1; i < pos-1; i++) {
        tmp = tmp->next;
    }

    Node* del_node = tmp->next;
    tmp->next = del_node->next;
    delete del_node;
    sz--;

}
