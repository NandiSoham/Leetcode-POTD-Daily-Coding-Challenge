// Problem Link -> https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

class Solution {
public:
    vector<int> resultArr;
    
    void performPostorderTraversal(Node* node) {
        if (!node)
            return;
        
        for (Node*& childNode : node->children) {
            performPostorderTraversal(childNode);
        }
        
        resultArr.push_back(node->val);
    }
    
    vector<int> postorder(Node* root) {
        resultArr.clear();
        performPostorderTraversal(root);
        return resultArr;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
