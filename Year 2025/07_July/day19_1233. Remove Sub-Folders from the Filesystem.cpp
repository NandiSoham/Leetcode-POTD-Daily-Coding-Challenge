// Problem Link -> https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> ansArr;

        ansArr.push_back(folder[0]); 
        for(int i = 1; i < folder.size(); i++) {
            string currentPath = folder[i];
            string parentPath = ansArr.back();
            parentPath += '/';

            if(currentPath.find(parentPath) != 0) {
                ansArr.push_back(currentPath);
            }
        }

        return ansArr;
    }
};



// time Complexity -> O(n logn)
// Space Complexity -> O(1)
