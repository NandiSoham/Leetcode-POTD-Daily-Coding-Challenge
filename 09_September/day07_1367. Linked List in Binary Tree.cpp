// Problem Link -> https://leetcode.com/problems/linked-list-in-binary-tree/description/

class Solution {
public:
    bool checkMachedPath(ListNode* head, TreeNode* root) {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;

        if(head->val != root->val) return false;

        return checkMachedPath(head->next, root->left) ||
               checkMachedPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return false;

        return checkMachedPath(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};



// Time Complexity -> O(m * n) [n = number of nodes in trees, m = number of nodes in linkedlist]
// Space Complexity -> O(1)
