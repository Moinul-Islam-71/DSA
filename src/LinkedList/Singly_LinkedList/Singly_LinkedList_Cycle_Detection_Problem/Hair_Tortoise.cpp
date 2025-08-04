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


int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);


    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = e;

    // Now the list is 10 -> 20 -> 30 -> 40 -> 50 -> 20 (cycle)

    Node* hair = head;
    Node* tortoise = head;
    bool flag = false;

    while(hair != NULL && hair->next != NULL) 
    {
        hair = hair->next->next;
        tortoise = tortoise->next;

        if(hair == tortoise) 
        {
            //Cycle detected
            flag = true;
            break;
        }
    }

    if(flag) 
        cout << "Cycle detected";
    else 
        cout << "No Cycle";

    return 0;
}
