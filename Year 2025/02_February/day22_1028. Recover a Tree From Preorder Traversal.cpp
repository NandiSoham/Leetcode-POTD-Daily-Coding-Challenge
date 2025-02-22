// Problem Link -> https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

class Solution {
public:
    int n;

    TreeNode* buildTree(const string& traversal, int& index, int depth) {
        if (index >= n) return nullptr;

        int dashCount = 0;
        while (index + dashCount < n && traversal[index + dashCount] == '-') {
            dashCount++;
        }

        if (dashCount != depth) return nullptr;

        index += dashCount;

        int value = 0;
        while (index < n && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(value);
        node->left  = buildTree(traversal, index, depth + 1);
        node->right = buildTree(traversal, index, depth + 1);

        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int index = 0;
        return buildTree(traversal, index, 0);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
