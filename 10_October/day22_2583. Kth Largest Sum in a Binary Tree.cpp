// Problem Link -> https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq; 

        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            int n = que.size();
            long levelSum = 0;
            
            while (n--) {
                TreeNode* node = que.front();
                que.pop();
                levelSum += node->val;
                
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
            pq.push(levelSum);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};

