// Problem Link -> https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    void generateHappyStrings(int n, string& currStr, vector<string>& ans){
        if(currStr.length() == n){
            ans.push_back(currStr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!currStr.empty() && currStr.back() == ch) continue;

            currStr.push_back(ch);
            generateHappyStrings(n, currStr, ans);
            currStr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string currStr = "";
        vector<string> ans;

        generateHappyStrings(n, currStr, ans);

        if(k > ans.size()) return "";
        return ans[k - 1];
    }
};



// Time Complexity -> O(n*2^n)
// Space Complexity -> O(n * 2^n)

// ========================================================================================
