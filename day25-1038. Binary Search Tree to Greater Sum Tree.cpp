// Problem Link -> https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

class Solution {
public:
    void solve(TreeNode* root, int& sum) {
        if (root == NULL)
            return;

        solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);

        return root;
    }
};



// Time Complexity -> O(n)
// Space Complexity ->O(1)
