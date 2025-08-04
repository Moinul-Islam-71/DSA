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

    //Update the list when the list was empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        sz++;
        return;
    }


    //Otherwise
    newNode->next = head;
    head = newNode;
    sz++;

}

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
    Node* tmp = head;


    // Traverse to the node just before the insertion point
    for (int i = 1; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
    sz++;
}

void printList(Node* head) {
    Node* tmp = head;

    while(tmp != NULL) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

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

    insert_at_tail(head, tail, 10);
    insert_at_tail(head, tail, 20);
    insert_at_tail(head, tail, 30);
    insert_at_tail(head, tail, 40);
    insert_at_tail(head, tail, 50);

    printList(head);
    
    insert_at_pos(head, tail, 3, 100);
    
    printList(head);

    delete_at_tail(head, tail);

    printList(head);

    return 0;
}