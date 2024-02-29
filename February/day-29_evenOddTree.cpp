class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool even_level= true;

        while(!que.empty()){
            int n = que.size();
            int prev;
            if(even_level) prev = INT_MIN;
            else prev = INT_MAX;

            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                if(even_level && (curr -> val % 2 == 0 || curr -> val <= prev)) return false;
                if(!even_level && (curr -> val % 2 != 0 || curr -> val >= prev)) return false;

                prev = curr -> val;
                if(curr -> left) que.push(curr -> left);
                if(curr -> right) que.push(curr -> right);
            }

            even_level = !even_level;
        }
        return true;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/even-odd-tree/description/
