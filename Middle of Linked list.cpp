#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 1. Linked list can be Even or odd 
         // Even case : stop the loop when fast will reach to NULL
          // Odd case : stop the loop when fast will reach to Tail
        while (fast != NULL && fast->next != NULL) {                
            slow = slow->next;   // slow node is increasing by 1
            fast = fast->next->next; // fast node is increasing by 2
        }
        return slow;  // slow is now at the middle node
    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle node value: " << mid->val << endl;

    return 0;
}
