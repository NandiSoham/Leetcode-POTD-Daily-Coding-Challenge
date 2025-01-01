// Problem Link -> https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int startIndex = 0, targetIndex = 0;

        while (startIndex < n || targetIndex < n) {
            while (startIndex < n && start[startIndex] == '_') {
                startIndex++;
            }
            while (targetIndex < n && target[targetIndex] == '_') {
                targetIndex++;
            }

            if (startIndex == n || targetIndex == n) {
                return startIndex == n && targetIndex == n;
            }

            if (start[startIndex] != target[targetIndex]) {
                return false;
            }

            if ((start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex)) {
                return false;
            }

            startIndex++;
            targetIndex++;
        }

        return true;
    }
};




// Time Complexity -> O(n)
// Space Complexity -> O(n)
