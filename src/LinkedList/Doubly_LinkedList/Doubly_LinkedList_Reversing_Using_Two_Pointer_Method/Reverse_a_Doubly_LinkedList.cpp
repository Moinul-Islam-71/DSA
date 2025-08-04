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

void new_line() {
    cout << endl;
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

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reverse_list(Node* &head, Node* &tail) {
    
    for (Node* i = head,  *j = tail; ( (i != j) && (j != i->prev) ) ; i = i->next, j = j->prev) {
        swap(i->data, j->data);
    }

}




int main() {

    Node* head = NULL;
    Node* tail = NULL;

    int val;

    cout << "Input: ";
    while(1) {
        cin >> val; 

        if(val == -1) break;

        insertAtTail(head, tail, val);
    }

    printList(head); new_line();

    reverse_list(head, tail);

    printList(head); new_line();
    
    return 0;
}
