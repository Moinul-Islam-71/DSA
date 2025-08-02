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

void delete_head(Node* &head, Node* &tail) {

    if(head == NULL || tail == NULL) {
        return;
    }

    Node* node_to_be_deleted = head;
    head = head->next;
    delete node_to_be_deleted;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        // If the list becomes empty, update tail as well
        tail = NULL;
    }

    sz--;

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

void deleteAtPos(Node* &head, Node* &tail, int idx) {
    if (idx < 0 || idx >= sz) {
        cout << "Invalid position" << endl;
        return;
    }
    if (idx == 0) {
        delete_head(head, tail);
        return;
    }
    if (idx == sz - 1) {
        deleteAtTail(head, tail);
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < idx; i++) {
        tmp = tmp->next;
    }

    tmp->prev->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }
    delete tmp;
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
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original List: ";
    printList(head);

    cout << "Deleting at position 2..." << endl;
    deleteAtPos(head, tail, 2);

    cout << "List after deleting at position 2: ";
    printList(head);

    return 0;
}
