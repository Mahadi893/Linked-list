#include <bits/stdc++.h>
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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert node at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete node at specific position
    void deleteAtPosition(int pos) {
        if (head == NULL || pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        // CASE 1: delete the head
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        for (int i = 1; curr != NULL && i < pos - 1; i++) {
            curr = curr->next;
        }

        // Position out of bounds
        if (curr == NULL || curr->next == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        Node* nodeTodel = curr->next;
        curr->next = nodeTodel->next;
        delete nodeTodel;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertEnd(val);
    }

    cout << "Enter position to delete: ";
    cin >> pos;

    list.deleteAtPosition(pos);

    cout << "List after deletion: ";
    list.printList();

    return 0;
}
