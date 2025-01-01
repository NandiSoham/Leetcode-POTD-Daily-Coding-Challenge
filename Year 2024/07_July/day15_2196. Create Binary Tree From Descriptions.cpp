// Problem Link -> https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> childNodes; 

        for (vector<int>& description : descriptions) {
            int parentValue = description[0];
            int childValue = description[1];
            int isLeftChild = description[2];

            if (nodeMap.find(parentValue) == nodeMap.end()) {
                nodeMap[parentValue] = new TreeNode(parentValue);
            }

            if (nodeMap.find(childValue) == nodeMap.end()) {
                nodeMap[childValue] = new TreeNode(childValue);
            }

            if (isLeftChild == 1) {
                nodeMap[parentValue]->left = nodeMap[childValue];
            } else {
                nodeMap[parentValue]->right = nodeMap[childValue];
            }

            childNodes.insert(childValue);
        }

        for (vector<int>& description : descriptions) {
            int parentValue = description[0];
            if (childNodes.find(parentValue) == childNodes.end()) {
                return nodeMap[parentValue];
            }
        }

       return NULL;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
