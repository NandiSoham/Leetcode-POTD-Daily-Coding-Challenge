// Problem Link -> https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/


// =================================== Approach - 1 ==================================

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;

        for(int i = 0; i < n - 1; i++){

            int zeroCount = 0;
            for(int j = 0; j <= i; j++){
                if(s[j] == '0') {
                    zeroCount++;
                }
            }

            int oneCount = 0;
            for(int j = i + 1; j < n; j++){
                if(s[j] == '1') {
                    oneCount++;
                }
            }

            result = max(result, zeroCount + oneCount);
        }

        return result;
    }
};



// Time Complexity -> O(n ^ 2)
// Space Complexity -> O(1)

// ===================================================================================

// =================================== Approach - 2 ==================================

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;
        int totalOnesCount = count(s.begin(), s.end(), '1');

        int zeroCount = 0;
        int leftSideOnesCount = 0;

        for(int i = 0; i < n - 1; i++){
            if(s[i] == '1') 
                leftSideOnesCount++;
            else
                zeroCount++;
            
            int rightSideOnesCount = totalOnesCount - leftSideOnesCount;
            result = max(result, zeroCount + rightSideOnesCount);
        }

        return result;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ===================================================================================

// =================================== Approach - 3 ==================================

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int maxScoreResult = INT_MIN;

        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                oneCount++;
            } else {
                zeroCount++;
            }

            maxScoreResult = max(maxScoreResult, zeroCount - oneCount);
        }

        if (s[n - 1] == '1') {
            oneCount++;
        }

        return maxScoreResult + oneCount;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ===================================================================================
