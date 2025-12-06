#include <iostream>
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


    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    void deleteMiddle() {

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        prev->next = slow->next;


        delete slow;
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
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }

    l.printList();

    l.deleteMiddle();

    cout << "List After Deleting Middle Node:\n";
    l.printList();

    return 0;
}
