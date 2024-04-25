// Problem Link -> https://leetcode.com/problems/longest-ideal-subsequence/description/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int>arr(n, 1);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(abs(s[i] - s[j]) <= k){
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};


// [PS: This approach might give TLE error because of high constraints]

// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------

// ---------------------------------------- Approach - 2  ---------------------------------------

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int>arr(26, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            int currCharIdx = s[i] - 'a';
            int leftIdxRange = max(0, currCharIdx - k);
            int rightIdxRange = min(25, currCharIdx + k);
            int longest = 0;

            for(int j = leftIdxRange; j <= rightIdxRange; j++){
                longest = max(longest, arr[j]);
            }
            arr[currCharIdx] = max(arr[currCharIdx], longest + 1);
            ans = max(ans, arr[currCharIdx]);
        }
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

//-----------------------------------------------------------------------------------------------
