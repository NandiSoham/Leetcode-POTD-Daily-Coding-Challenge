// Problem Link -> https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> bitmaskMap;
        bitmaskMap[0] = -1;
        int counter = 0, result = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                counter ^= (1 << (s[i] - 'a'));
            }

            if (bitmaskMap.count(counter)) {
                result = max(result, i - bitmaskMap[counter]);
            } else {
                bitmaskMap[counter] = i;
            }
        }

        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
