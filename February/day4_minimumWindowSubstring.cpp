class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char,int> mpp;
        if(t.length() > n) return "";

        for(char &ch : t){
            mpp[ch]++;
        }

        int i=0, j = 0;
        int minStart = 0;
        int requiredCount = t.length();
        int minWindowSize = INT_MAX;

        while(j < n){
            char ch_j = s[j];
            if(mpp[ch_j] > 0){
                requiredCount --;
            } 
            mpp[ch_j]--;

            while (requiredCount == 0){
                int curMinWindow = j-i+1;

                if(minWindowSize > curMinWindow){
                    minWindowSize = curMinWindow;
                    minStart = i;
                }
                char ch_i = s[i];
                mpp[ch_i]++;

                if(mpp[ch_i] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minStart, minWindowSize);
    }
};


// Time Complexity -> O(n)
//Space Complexity -> O(m); m = length of the input string 't'
// Problem Link - > https://leetcode.com/problems/minimum-window-substring/description/
