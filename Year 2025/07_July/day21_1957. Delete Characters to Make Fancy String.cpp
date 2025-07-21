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

// Time Complexity -> O(n)
// Space Complexity -> O(1)  not considering and ans string

// ==========================================================================


// =============================== Approach - 2 =============================

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n < 3) return s;

        int j = 2;
        for(int i = 2; i < n; i++){
            if(s[i] != s[j - 1] || s[i] != s[j - 2]){
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
        return s;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ==========================================================================
