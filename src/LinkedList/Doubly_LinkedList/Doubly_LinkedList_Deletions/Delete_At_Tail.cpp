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
    sz++;

    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

void deleteAtTail(Node* &head, Node* &tail) {

    if(head == NULL || tail == NULL) {
        return;
    }

    Node* node_to_be_deleted = tail;
    tail = tail->prev;
    delete node_to_be_deleted;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        // If the list becomes empty, update head as well
        head = NULL;
    }

    sz--;

}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);

    cout << "Original List: ";
    printList(head);

    cout << "Deleting tail..." << endl;
    deleteAtTail(head, tail);

    cout << "List after deleting tail: ";
    printList(head);

    return 0;
}
