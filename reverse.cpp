#include <bits/stdc++.h>
using namespace std;

// Node structure
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Solution class containing reverse function
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;     // Save next node
            curr->next = prev;     // Reverse pointer
            prev = curr;           // Move prev forward
            curr = next;           // Move curr forward
        }

        return prev;  // New head
    }
};

// Function to insert at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) {
        return newNode;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;
    Solution obj;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertEnd(head, x);
    }

    cout << "\nOriginal List: ";
    printList(head);

    head = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
