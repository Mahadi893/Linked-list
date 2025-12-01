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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at end
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

    // Find maximum value
    int findMax() {
        if (head == NULL) return -1;   // list empty

        int maxi = head->data;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data > maxi)
                maxi = temp->data;
            temp = temp->next;
        }

        return maxi;
    }

    // Find minimum value
    int findMin() {
        if (head == NULL) return -1;   // list empty

        int mini = head->data;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data < mini)
                mini = temp->data;
            temp = temp->next;
        }

        return mini;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(15);
    list.insertEnd(7);
    list.insertEnd(29);
    list.insertEnd(3);
    list.insertEnd(18);

    cout << "Linked List: ";
    list.display();

    cout << "Maximum value = " << list.findMax() << endl;
    cout << "Minimum value = " << list.findMin() << endl;

    return 0;
}
