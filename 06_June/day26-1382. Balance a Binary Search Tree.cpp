// Problem Link -> https://leetcode.com/problems/balance-a-binary-search-tree/description/

class Solution {
public:

    void inOrderFunc(TreeNode* root, vector<int>& nodeVec){
        if(root == NULL) return;
        inOrderFunc(root->left, nodeVec);
        nodeVec.push_back(root->val);
        inOrderFunc(root->right, nodeVec);
    }

    TreeNode* constructBalancedBST(int leftPtr, int rightPtr, vector<int>& nodeVec){
        if(leftPtr > rightPtr) return NULL;
        int mid = (leftPtr + rightPtr)/2;
        TreeNode* node = new TreeNode(nodeVec[mid]);
        node->left = constructBalancedBST(leftPtr, mid - 1, nodeVec);
        node->right = constructBalancedBST(mid + 1, rightPtr, nodeVec);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodeVec;
        inOrderFunc(root, nodeVec);
        int leftPtr = 0, rightPtr = nodeVec.size() - 1;
        return constructBalancedBST(leftPtr, rightPtr, nodeVec);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
