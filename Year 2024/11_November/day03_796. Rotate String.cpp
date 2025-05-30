// Problem Link -> https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s + s).find(goal) != string::npos)
            return true;
        
        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
