// Problem Link -> https://leetcode.com/problems/count-number-of-bad-pairs/description/

// ======================================= Approach - 1 (TLE)====================================

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairsCount = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i < j && j - i != nums[j] - nums[i]){
                    badPairsCount++;
                }
            }
        }

        return badPairsCount;
    }
};



// Time Complexity -> O(n^2)
// Space COmplexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairsCount = 0;

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] - i;
        }

        unordered_map<int, int> freqMap;
        freqMap[nums[0]] = 1;

        for(int j = 1; j < n; j++){
            int currentCount = freqMap[nums[j]];
            int countNumsBeforeJ = j;
            int currBadPairCount = countNumsBeforeJ - currentCount;

            badPairsCount += currBadPairCount;
            freqMap[nums[j]]++;
        }

        return badPairsCount;
    }
};



// Time Complexity -> O(n)
// Space COmplexity -> O(n)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairsCount = 0;
        unordered_map<int, int> freqMap;

        for(int i = 0; i < n; i++){
            int diff = nums[i] - i;
            int goodPairsCount = freqMap[diff];
            int totalPairsCount = i;
            
            badPairsCount += totalPairsCount - goodPairsCount;
            freqMap[diff]++;
        }

        return badPairsCount;
    }
};



// Time Complexity -> O(n)
// Space COmplexity -> O(n)

// =========================================================================================
