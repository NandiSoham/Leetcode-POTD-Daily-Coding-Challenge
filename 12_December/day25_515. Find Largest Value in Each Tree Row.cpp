// Problem Link -> https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        vector<int> levelMaxValues;
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int levelMax = INT_MIN;
            
            while (levelSize--) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                
                levelMax = max(levelMax, currentNode->val);
                
                if (currentNode->left)
                    nodeQueue.push(currentNode->left);
                
                if (currentNode->right)
                    nodeQueue.push(currentNode->right);
            }
            
            levelMaxValues.push_back(levelMax);
        }
        
        return levelMaxValues;
    }
};
