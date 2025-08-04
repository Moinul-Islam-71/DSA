#include <bits/stdc++.h>
using namespace std;

int sz = 0;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to print the list from tail to head
void printReverse(Node* tail) {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}


int main() {
    // Create a sample doubly linked list
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    // Connect the nodes
    node1->next = node2;  //10 -> 20
    node2->prev = node1;  //10 <-> 20 
    node2->next = node3;  //20 -> 30
    node3->prev = node2;  //20 <-> 30

    Node* tail = node3;

    // Print the list from tail to head
    cout << "List from tail to head: ";
    printReverse(tail);

    return 0;
}