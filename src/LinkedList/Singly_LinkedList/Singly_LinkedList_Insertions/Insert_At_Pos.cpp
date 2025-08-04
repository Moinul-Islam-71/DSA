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

void insert_at_tail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data); 
    sz++;

    //Update the list when the list was empty
    if(head == NULL || tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    //Otherwise
    tail->next = newNode;
    tail = newNode;

}

void insert_at_pos(Node* &head, Node* &tail, int pos, int data) {

    // Handling a corner case of Invalid Position...
    if (pos < 1 || pos > sz + 1) {
        // Handle invalid position. You might want to print an error message.
        // cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) {
        insert_at_head(head, tail, data);
        return;
    }

    if (pos == sz + 1) { //incorrect logic: pos == sz 
        insert_at_tail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    sz++;
    Node* tmp = head;


    // Traverse to the node just before the insertion point
    for (int i = 1; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
}
