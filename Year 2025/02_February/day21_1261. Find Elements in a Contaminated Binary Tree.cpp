// Problem Link -> https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

// ======================================= Approach - 1 (DFS) ====================================

class FindElements {
public:
    unordered_set<int> valSet;

    void dfsFunc(TreeNode* root, int x){
        if(!root) return;

        root -> val = x;
        valSet.insert(x);
        dfsFunc(root -> left, 2 * x + 1);
        dfsFunc(root -> right, 2 * x + 2);
    }

    FindElements(TreeNode* root) {
        dfsFunc(root, 0);
    }
    
    bool find(int target) {
        return valSet.count(target);
    }
};



// Time Complexity ->O(n)
// Space Complexity -> O(n)

// =============================================================================================
