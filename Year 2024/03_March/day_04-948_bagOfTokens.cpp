class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int curScore = 0, maxScore = 0;
        int left = 0, right = n - 1;

        sort(tokens.begin(), tokens.end());

        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                curScore += 1;
                left++;
                maxScore = max(maxScore, curScore);
            } else if(curScore >= 1){
                power += tokens[right];
                curScore -= 1;
                right--;
            } else return maxScore;
        }
        return maxScore;
    }
};



// Time Complexity -> O(n logn)
// Space COmplexity -> O(1)
// Problem Link -> https://leetcode.com/problems/bag-of-tokens/
