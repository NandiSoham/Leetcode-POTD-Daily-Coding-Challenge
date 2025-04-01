// Problem Link -> https://leetcode.com/problems/solving-questions-with-brainpower/description/

class Solution {
public:
    
    int totalQuestions;
    
    long long getMaxPoints(int index, vector<vector<int>>& questions, vector<long long> &memo) {
        
        if(index >= totalQuestions)
            return 0;
        
        if(memo[index] != -1)
            return memo[index];
        
        long long chooseCurrent = questions[index][0] + getMaxPoints(index + questions[index][1] + 1, questions, memo);
        
        long long skipCurrent = getMaxPoints(index + 1, questions, memo);
        
        return memo[index] = max(chooseCurrent, skipCurrent);
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        totalQuestions = questions.size();
        vector<long long> memo(totalQuestions + 1, -1);
        return getMaxPoints(0, questions, memo);
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
