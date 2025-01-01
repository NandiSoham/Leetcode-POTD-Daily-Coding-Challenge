// Problem Link -> https://leetcode.com/problems/delete-node-in-a-linked-list/description/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prevNode = NULL;

        while(node != NULL && node->next != NULL){
            node->val = node->next->val;
            prevNode = node;
            node = node->next;
        }

        prevNode->next = NULL;
        delete(node);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
