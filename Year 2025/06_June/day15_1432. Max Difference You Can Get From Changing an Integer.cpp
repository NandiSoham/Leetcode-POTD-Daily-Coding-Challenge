// Problem Link -> https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/

class Solution {
public:
    int maxDiff(int num) {
        string maxStr = to_string(num);
        string minStr = maxStr;

        int nonNineIdx = maxStr.find_first_not_of('9');
        if(nonNineIdx != string::npos) {
            char targetChar = maxStr[nonNineIdx];
            replace(begin(maxStr), end(maxStr), targetChar, '9');
        }

        for(int i = 0; i < minStr.length(); i++) {
            char currChar = minStr[i];
            if(i == 0) {
                if(currChar != '1') {
                    replace(begin(minStr), end(minStr), currChar, '1');
                    break;
                }
            } else if(currChar != '0' && currChar != minStr[0]) {
                replace(begin(minStr), end(minStr), currChar, '0');
                break;
            }
        }
        return stoi(maxStr) - stoi(minStr);
    }
};



// time Complexity -> O(log10(num))
// Space Complexity -> O(log10(num))
