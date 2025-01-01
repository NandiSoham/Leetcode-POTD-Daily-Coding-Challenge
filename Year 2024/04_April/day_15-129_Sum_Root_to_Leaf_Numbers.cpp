class Solution {
public:

    int solve(TreeNode* root, int curr){
        if(!root) return 0;

        curr = (curr * 10) + root->val;

        if(root->left == NULL && root->right == NULL)
            return curr;
        
        int leftSideSum = solve(root->left, curr);
        int rightSideSum = solve(root->right, curr);

        return leftSideSum + rightSideSum;
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
