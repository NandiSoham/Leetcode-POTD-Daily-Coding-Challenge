// Problem Link -> https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(root->val == target && root->right == NULL && root->left == NULL)
            return NULL;
        
        return root;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(height of the tree)
