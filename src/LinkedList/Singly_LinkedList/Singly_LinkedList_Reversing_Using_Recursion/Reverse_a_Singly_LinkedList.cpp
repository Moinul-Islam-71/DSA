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



void insert_at_tail(Node* &head, Node* &tail, int data) {

    Node* newNode = new Node(data); 

    //Update the list when the list was empty
    if(head == NULL || tail == NULL) {
        head = newNode;
        tail = newNode;
        sz++;
        return;
    }

    //Otherwise
    tail->next = newNode;
    tail = newNode;
    sz++;

}



void print_reverse(Node* tmp) {
    if(tmp == NULL) {
        return;
    }

    print_reverse(tmp->next);
    cout << tmp->data << " ";
}

void reverse_list(Node* &head, Node* &tail, Node* tmp) {

    if(tmp->next == NULL) {
        head = tmp;
        return;
    }

    reverse_list(head, tail, tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;
    tail = tmp;
    
}

void printList(Node* tmp) {
    if(tmp == NULL) {
        return;
    }

    cout << tmp->data << " ";
    printList(tmp->next);
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    int val;

    cout << "Input: ";
    while(1) {
        cin >> val; 

        if(val == -1) break;

        insert_at_tail(head, tail, val);
    }

    cout << "printing list in forward way:" << endl;
    printList(head);
    cout << endl;

    cout << "printing list in reverse way:" << endl;
    print_reverse(head);
    cout << endl;

    reverse_list(head, tail, head);

    cout << "After reversing the list:" << endl;

    cout << "printing list in forward way:" << endl;
    printList(head);
    cout << endl;

    cout << "printing list in reverse way:" << endl;
    print_reverse(head);
    cout << endl;
    
    return 0;
}
