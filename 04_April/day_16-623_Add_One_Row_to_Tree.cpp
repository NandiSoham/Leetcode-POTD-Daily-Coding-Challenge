class Solution {
public:

    TreeNode* addFunc(TreeNode* root, int val, int depth, int curDepth){
        if(root == NULL) return NULL;
        if(curDepth == depth -1){
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }
        root->left = addFunc(root->left, val, depth, curDepth + 1);
        root->right = addFunc(root->right, val, depth, curDepth + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            return newRoot;
        }
        int curDepth = 1;
        return addFunc(root, val, depth, curDepth);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/add-one-row-to-tree/description/
