// Problem Link -> https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }

        int leftEvalution = evaluateTree(root->left);
        int rightEvalution = evaluateTree(root->right);

        if(root->val == 2)
            return leftEvalution | rightEvalution;
        return leftEvalution & rightEvalution;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(x), where x = depth of the tree
