// Problem Link -> https://leetcode.com/problems/delete-nodes-and-return-forest/description/

class Solution {
public:

    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& nodeSet, vector<TreeNode*>& ans){
        if(root == NULL) return NULL;
        root->left = deleteHelper(root->left, nodeSet, ans);
        root->right = deleteHelper(root->right, nodeSet, ans);

        if(nodeSet.find(root->val) != nodeSet.end()){
            if(root->left != NULL){
                ans.push_back(root->left);
            }

            if(root->right != NULL){
                ans.push_back(root->right);
            }
            return NULL;
        } else return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> nodeSet;

        for(auto &it : to_delete){
            nodeSet.insert(it);
        }

        deleteHelper(root, nodeSet, ans);
        if(nodeSet.find(root->val) == nodeSet.end()){
            ans.push_back(root);
        }

        return ans;
    }
};




// Time Complexity -> O(n)
// Space Complexity -> O(n)
