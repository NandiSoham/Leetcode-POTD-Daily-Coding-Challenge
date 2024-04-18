// Problem Link -> https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

// ---------------------------------------- Approach - 1 (Using DFS) ---------------------------------------


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

// --------------------------------------------------------------------------------------------------------

// ---------------------------------------- Approach - 2 (Using BFS) ---------------------------------------

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> queOfNode;
        
        string ans = "";
        queOfNode.push({root, string(1, root->val + 'a')});
        
        while(!queOfNode.empty()) {
            
            auto[node, currStr] = queOfNode.front();
            queOfNode.pop();
            
            if(node->left == NULL && node->right == NULL) {
                if(ans == "" || ans > currStr) {
                    ans = currStr;
                }
            }
            
            if(node->left) {
                queOfNode.push({node->left, char(node->left->val + 'a') + currStr});
            }
            
            if(node->right) {
                queOfNode.push({node->right, char(node->right->val + 'a') + currStr});
            }
            
        }
        
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

--------------------------------------------------------------------------------------------------------
