// Problem Link -> https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

class Solution {
public:
    void createGraph(TreeNode* currentNode, TreeNode* parent,
                     unordered_map<TreeNode*, vector<TreeNode*>>& adjacencyList,
                     unordered_set<TreeNode*>& leafNodes) {
        if (currentNode == NULL) {
            return;
        }

        if (currentNode->left == NULL && currentNode->right == NULL) {
            leafNodes.insert(currentNode);
        }

        if (parent != NULL) {
            adjacencyList[currentNode].push_back(parent);
            adjacencyList[parent].push_back(currentNode);
        }

        createGraph(currentNode->left, currentNode, adjacencyList, leafNodes);
        createGraph(currentNode->right, currentNode, adjacencyList, leafNodes);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adjacencyList;
        unordered_set<TreeNode*> leafNodes;

        createGraph(root, NULL, adjacencyList, leafNodes);

        int goodPairsCount = 0;

        for (auto& leafNode : leafNodes) {
            queue<TreeNode*> nodeQueue;
            unordered_set<TreeNode*> visitedNodes;
            nodeQueue.push(leafNode);
            visitedNodes.insert(leafNode);

            for (int level = 0; level <= distance; level++) {
                int levelSize = nodeQueue.size();
                while (levelSize--) {
                    TreeNode* currentNode = nodeQueue.front();
                    nodeQueue.pop();

                    if (currentNode != leafNode &&
                        leafNodes.count(currentNode)) {
                        goodPairsCount++;
                    }

                    for (auto& neighbor : adjacencyList[currentNode]) {
                        if (!visitedNodes.count(neighbor)) {
                            nodeQueue.push(neighbor);
                            visitedNodes.insert(neighbor);
                        }
                    }
                }
            }
        }
        return goodPairsCount / 2;
    }
};




// Time Complexity -> O(n^2)
// Space Complexity -> O(n)
