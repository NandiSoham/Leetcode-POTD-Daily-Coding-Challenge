// Problem Link -> https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

class Solution {
public:

    int helper(TreeNode* root, int& moves){
        if(!root) return NULL;

        int leftSideSolve = helper(root->left, moves);
        int rightSideSolve = helper(root->right, moves);

        moves += abs(leftSideSolve) + abs(rightSideSolve);

        return (leftSideSolve + rightSideSolve + root->val) - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(H), where H = height of the tree
