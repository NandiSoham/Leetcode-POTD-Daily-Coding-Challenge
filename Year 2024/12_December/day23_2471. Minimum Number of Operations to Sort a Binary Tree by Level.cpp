class Solution {
public:
    int countMinSwapsToSort(vector<int>& values) {
        int swapCount = 0;
        vector<int> sortedValues(begin(values), end(values));
        
        sort(begin(sortedValues), end(sortedValues));

        unordered_map<int, int> valueToIndex;
        for (int index = 0; index < values.size(); index++) {
            valueToIndex[values[index]] = index;
        }

        for (int index = 0; index < values.size(); index++) {
            if (values[index] == sortedValues[index]) {
                continue;
            }
            
            int correctIndex = valueToIndex[sortedValues[index]];
            valueToIndex[values[index]] = correctIndex;
            valueToIndex[values[correctIndex]] = index;
            swap(values[correctIndex], values[index]);
            swapCount++;
        }

        return swapCount;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        int totalSwaps = 0;

        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            vector<int> levelValues;

            while (levelSize--) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();
                levelValues.push_back(currentNode->val);

                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }

                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }

            totalSwaps += countMinSwapsToSort(levelValues);
        }

        return totalSwaps;
    }
};



//Time Complexity -> O(n + level * wlogw), level = total levels, w = number of nodes in a level
//Space Complexity -> O(n)
