// Problem Link -> https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int currentLevel = 0;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vector<TreeNode*> nodesAtLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                nodesAtLevel.push_back(currentNode);

                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }

            if (currentLevel % 2 == 1) {
                int left = 0, right = nodesAtLevel.size() - 1;
                while (left < right) {
                    swap(nodesAtLevel[left]->val, nodesAtLevel[right]->val);
                    left++;
                    right--;
                }
            }
            currentLevel++;
        }

        return root;
    }
};




// Time Complexity -> O(n)
// Space Complexity -> O(n)
