class Solution {
public:

    int helper(TreeNode* curNode, TreeNode* parentNode){
        if(curNode == NULL) return 0;

        if(curNode->left == NULL && curNode->right == NULL){
            if(parentNode != NULL && parentNode->left == curNode){
                return curNode -> val;
            }
        }

        int leftPartLeftLeavesSum = helper(curNode->left, curNode);
        int rightPartLeftLeavesSum = helper(curNode->right, curNode);

        return leftPartLeftLeavesSum + rightPartLeftLeavesSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, NULL);
    }
};



// Time Complexity -> O(n)
// Space COmplexity -> O(1)
// Problem Link -> https://leetcode.com/problems/sum-of-left-leaves/description/
