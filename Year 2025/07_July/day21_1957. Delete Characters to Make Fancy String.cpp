// Problem Link -> https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

// =============================== Approach - 1 =============================

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        ans.push_back(s[0]);
        int freq = 1;

        for(int i = 1; i < n; i++){
            if(s[i] == ans.back()){
                freq++;
                if(freq < 3){
                    ans.push_back(s[i]);
                }
            } else{
                ans.push_back(s[i]);
                freq = 1;
            }
        }

        return ans;
    }
};

// time Complexity -> O(n)
// Space Complexity -> O(1)  not considering and ans string

// ==========================================================================
