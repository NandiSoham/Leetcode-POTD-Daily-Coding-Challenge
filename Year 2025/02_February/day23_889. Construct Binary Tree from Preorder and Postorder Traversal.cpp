// Problem Link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    TreeNode* buildTree(int preStart, int postStart, int preEnd, vector<int>& preorder, vector<int>& postorder){
        if (preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;

        int leftSubtreeRoot = preorder[preStart + 1];
        int j = postStart;

        while(postorder[j] != leftSubtreeRoot){
            j++;
        }

        int nodeCount = j - postStart + 1;

        root -> left = buildTree(preStart + 1, postStart, preStart + nodeCount, preorder, postorder);
        root -> right = buildTree (preStart + nodeCount + 1, j + 1, preEnd, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(0, 0, preorder.size() - 1, preorder, postorder);
    }
};



// Time Complexity ->O(n^2)
// Space Complexity -> O(n)

// ===============================================================================================
