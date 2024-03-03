class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        for(int i = 0; i < n; i++){
            fastPointer = fastPointer->next;
        }
        if(fastPointer == NULL) return head->next;
        while(fastPointer->next != NULL){
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }

        ListNode* delNode = slowPointer->next;
        slowPointer->next = slowPointer->next->next;
        delete delNode;
        
        return head;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link-> https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
