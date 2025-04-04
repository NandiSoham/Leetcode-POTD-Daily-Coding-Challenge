// Problem Link -> https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/

class Solution {
    pair<TreeNode*, int> funcFindingLCA(TreeNode* currentNode) {
        if (currentNode == NULL) {
            return {NULL, 0};
        }

        pair<TreeNode*, int> leftSubtree = funcFindingLCA(currentNode->left);
        pair<TreeNode*, int> rightSubtree = funcFindingLCA(currentNode->right);

        if (leftSubtree.second == rightSubtree.second) {
            return {currentNode, leftSubtree.second + 1};
        }
        else if (leftSubtree.second > rightSubtree.second) {
            return {leftSubtree.first, leftSubtree.second + 1};
        }
        else {
            return {rightSubtree.first, rightSubtree.second + 1};
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return funcFindingLCA(root).first;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(h)
