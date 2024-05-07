// Problem Link -> https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5){
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }

        ListNode* currNode = head;
        while(currNode != NULL){
            currNode->val = (currNode->val * 2) % 10;

            if(currNode->next != NULL && currNode->next->val >= 5){
                currNode->val += 1;
            }
            currNode = currNode->next;
        }
        return head;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
