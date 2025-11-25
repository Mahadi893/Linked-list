#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Delete node at position 'pos'
void deleteAtPosition(Node* &head, int pos) {
    if (head == NULL || pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    // If deleting head
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int count = 1;

    // Traverse to the (pos-1) node
    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    // If position out of range
    if (current == NULL || current->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Delete the node
    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node{x, NULL};

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    cout << "\nCurrent List: ";
    printList(head);

    int pos;
    cout << "\nEnter position to delete: ";
    cin >> pos;

    deleteAtPosition(head, pos);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
