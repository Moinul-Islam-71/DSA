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

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    sz++;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

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

void insert_any_pos(Node* &head, Node* &tail, int idx, int data) {
    if (idx < 0 || idx > sz) {
        cout << "Invalid position" << endl;
        return;
    }
    if (idx == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    if (idx == sz) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* tmp = head;
    for (int i = 0; i < idx - 1; i++) {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    sz++;
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
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original List: ";
    printList(head);

    cout << "Inserting 30 at position 2" << endl;
    insert_any_pos(head, tail, 2, 30);


    cout << "List after insertion: ";
    printList(head);

    return 0;
}
