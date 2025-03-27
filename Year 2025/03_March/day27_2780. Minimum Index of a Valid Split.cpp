// Problem Link -> https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> leftFreq;  
        unordered_map<int, int> rightFreq; 

        for(int &num : nums) {
            rightFreq[num]++;
        }

        for(int i = 0; i < n; i++) {
            int currentNum = nums[i];

            leftFreq[currentNum]++;
            rightFreq[currentNum]--;

            int leftSize = i + 1;
            int rightSize = n - i - 1;

            if(leftFreq[currentNum] * 2 > leftSize && rightFreq[currentNum] * 2 > rightSize){
                return i;
            }
        }

        return -1;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =========================================================================================
