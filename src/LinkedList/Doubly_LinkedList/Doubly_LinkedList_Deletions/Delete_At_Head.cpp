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

void insertAtTail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data);
    sz++; // Increment size of the list

    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

void delete_head(Node* &head, Node* &tail) {

    // Check if the list is empty before attempting to delete
    if(head == NULL || tail == NULL) {
        return;
    }

    Node* node_to_be_deleted = head;
    head = head->next;
    delete node_to_be_deleted;

    if (head != NULL) {
        // If the list is not empty after deletion, update head's prev to NULL
        head->prev = NULL;
    } else {
        // If the list becomes empty, update tail as well
        tail = NULL;
    }

    sz--;

}


// Function to print the list from head to tail
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Function to print the list from tail to head
void printReverse(Node* tail) {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void freeList(Node* &head) {
    // If the list is empty, nothing to free
    if (head == NULL) {
        return;
    }

    Node* current = head;

    // Traverse the list and free each node
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    // After freeing all nodes, set head to NULL
    head = NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);

    cout << "Original List: ";
    printList(head);

    cout << "Deleting head..." << endl;
    delete_head(head, tail);

    cout << "List after deleting head: ";
    printList(head);

    freeList(head);


    // Check if the list is empty after deletion
    if (head == NULL && tail == NULL) {
        cout << "List is now empty." << endl;
    } else {
        cout << "List is not empty." << endl;
    }

    return 0;
}
