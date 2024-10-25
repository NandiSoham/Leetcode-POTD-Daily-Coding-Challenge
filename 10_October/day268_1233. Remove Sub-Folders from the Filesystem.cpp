// Problem Link -> https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string currFolder = folder[i];
            string lastFolder = result.back() + '/';

            if (currFolder.find(lastFolder) != 0) {
                result.push_back(currFolder);
            }
        }

        return result;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
