// Problem Link -> https://leetcode.com/problems/crawler-log-folder/description/

// ------------------------------- Approach - 1 ------------------------------

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> depthStack;

        for (string& log : logs) {
            if (log == "../") {
                if (!depthStack.empty()) {
                    depthStack.pop();
                }
            } else if (log == "./")
                continue;
            else
                depthStack.push(log);
        }

        return depthStack.size();
    }
};



// Time Complexity -> O(n)
// Space Complexity O(n)

// ---------------------------------------------------------------------------
