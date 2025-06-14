// Problem Link -> https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/


class Solution {
public:
    int minMaxDifference(int num) {
        string minVersion = to_string(num);
        string maxVersion = to_string(num);
        int n = minVersion.length();

        char replaceChar = ' ';
        for(int i = 0; i < n; i++) {
            if(maxVersion[i] != '9') {
                replaceChar = maxVersion[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxVersion[i] == replaceChar) {
                maxVersion[i] = '9';
            }
        }

        replaceChar = minVersion[0];
        for(int i = 0; i < n; i++) {
            if(minVersion[i] == replaceChar) {
                minVersion[i] = '0';
            }
        }

        return stoi(maxVersion) - stoi(minVersion);
    }
};



// Time Complexity -> O(log10(n))
// Space Complexity -> O(log10(n))
