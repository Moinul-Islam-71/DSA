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

void insert_at_head(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data); 
    sz++;

    //Update the list when the list was empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }


    //Otherwise
    newNode->next = head;
    head = newNode;

}
