class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode* prev = NULL;
         ListNode* curr = head;
         ListNode* next = NULL;
         while(curr!=NULL)
         {
            next = curr -> next;  // Preserve the next node address in next
            curr -> next = prev;  // current node is pointing and connecting with previous node
            prev = curr;
            curr = next;
         }
         return prev;
    }
};

