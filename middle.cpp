#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
       if(head==NULL)
       {
              return;  // List is empty, nothing to pop
       }
       else{
             Node* temp=head;  // store the current head in temp
             head=head->next;  // move head to the next node(previous second node)
             temp->next=NULL;  // disconnect the old head from the list
             delete temp;      // free the memory occupied by the old head
       }
    }   

    void pop_back()
    {
        if(head==NULL)
        {
            return ; // List is empty, nothing to pop
        }
        else{
            Node* temp = head;
            while(temp->next != tail)
            {
                temp = temp->next; // traverse to the second last node
            }
            temp->next = NULL; // disconnect the last node from the list
            delete tail;       // free the memory occupied by the last node
            tail = temp;       // update tail to the second last node
        }
    }

    void insert(int pos, int val)
    {
        if(pos<0)
        {
            return; // Invalid position
        }
        if(pos==0)
        {
            push_front(val); // Insert at the front
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0; i<pos-1; i++)
        {
            temp = temp->next; // traverse to the node before the position
        }
        newNode->next = temp->next; // link the new node to the next node
        temp->next = newNode;       // link the previous node to the new node
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List l;
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_back(40);
    l.push_back(5);

    l.pop_front();

    l.pop_back();

    l.insert(1, 150);

    l.printList();

    return 0;
}