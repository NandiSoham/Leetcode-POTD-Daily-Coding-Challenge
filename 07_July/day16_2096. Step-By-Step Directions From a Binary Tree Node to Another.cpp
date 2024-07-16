// Problem Link -> https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int node1, int node2) {
        if (!root) {
            return NULL;
        }

        if (root->val == node1 || root->val == node2) {
            return root;
        }

        TreeNode* leftSubtreeLCA = lowestCommonAncestor(root->left, node1, node2);
        TreeNode* rightSubtreeLCA = lowestCommonAncestor(root->right, node1, node2);

        if (leftSubtreeLCA && rightSubtreeLCA) {
            return root;
        }

        return leftSubtreeLCA ? leftSubtreeLCA : rightSubtreeLCA;
    }

    bool findPath(TreeNode* currentNode, int target, string& path) {
        if (currentNode == NULL) {
            return false;
        }

        if (currentNode->val == target) {
            return true;
        }

        // Explore left subtree
        path.push_back('L');
        if (findPath(currentNode->left, target, path)) {
            return true;
        }
        path.pop_back();

        // Explore right subtree
        path.push_back('R');
        if (findPath(currentNode->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string pathFromLcaToStart = "";
        string pathFromLcaToDest = "";

        findPath(LCA, startValue, pathFromLcaToStart);
        findPath(LCA, destValue, pathFromLcaToDest);

        string resultPath = "";

        for (int i = 0; i < pathFromLcaToStart.length(); i++) {
            resultPath.push_back('U');
        }

        resultPath += pathFromLcaToDest;

        return resultPath;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
