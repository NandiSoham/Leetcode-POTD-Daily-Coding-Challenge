// Problem link -> https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharSuffix(n);

        minCharSuffix[n - 1] = s[n - 1];
        for(int idx = n - 2; idx >= 0; idx--) {
            minCharSuffix[idx] = min(s[idx], minCharSuffix[idx + 1]);
        }

        string stackString = "";
        string ans = "";

        int currIdx = 0; 
        while(currIdx < n) {
            stackString.push_back(s[currIdx]);

            char currMin = (currIdx + 1 < n) ? minCharSuffix[currIdx + 1] : s[currIdx];

            while(!stackString.empty() && stackString.back() <= currMin) {
                ans += stackString.back();
                stackString.pop_back();
            }

            currIdx++;
        }

        while(!stackString.empty()) {
            ans += stackString.back();
            stackString.pop_back();
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
