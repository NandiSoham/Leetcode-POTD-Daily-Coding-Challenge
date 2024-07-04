// Problem Link -> https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        ListNode* temp = head->next;
        int currSum = 0;

        while(temp){
            if(temp->val != 0){
                currSum += temp->val;
                temp = temp->next;
            } else {
                ptr->next = new ListNode (currSum);
                ptr = ptr->next;
                currSum = 0;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
