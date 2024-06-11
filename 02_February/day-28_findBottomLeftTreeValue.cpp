class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int bottomLeft;
        que.push(root);

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            bottomLeft = node -> val;

            if(node -> right) que.push(node -> right);
            if(node -> left) que.push(node -> left);
        }
        return bottomLeft;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/find-bottom-left-tree-value/description/
