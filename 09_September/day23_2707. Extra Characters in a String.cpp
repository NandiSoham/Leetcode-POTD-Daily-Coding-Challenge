// Problem Link -> https://leetcode.com/problems/extra-characters-in-a-string/description/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(begin(dict), end(dict));

        vector<int> t(n+1, 0); 

        for(int i = n - 1; i >= 0; i--) {
            t[i] = 1 + t[i + 1];

            for(int j = i; j < n; j++) {
                string curr = s.substr(i, j - i + 1); 
                if(st.count(curr)) {
                    t[i] = min(t[i], t[j + 1]); 
                }
            }
        }

        return t[0]; 
    }
};
