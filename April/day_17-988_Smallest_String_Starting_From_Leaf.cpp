class Solution {
public:

    string ansStr = "";

    void dfs(TreeNode* root, string currStr){
        if(!root) return;
        currStr = char(root->val + 'a') + currStr;

        if(!root->left && !root->right){
            if(ansStr == "" || ansStr > currStr)
                ansStr = currStr;
            
            return;
        }

        dfs(root->left, currStr);
        dfs(root->right, currStr);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ansStr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
