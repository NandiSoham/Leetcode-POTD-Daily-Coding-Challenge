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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int majorityElement = -1;
        int majorityCount = 0;

        for(int i = 0; i < n; i++) {
            if(majorityCount == 0) {
                majorityElement = nums[i];
                majorityCount = 1;
            } else if(nums[i] == majorityElement) {
                majorityCount++;
            } else {
                majorityCount--;
            }
        }

        int totalMajorityCount = 0;
        for(int &num : nums) {
            if(num == majorityElement) {
                totalMajorityCount++;
            }
        }

        majorityCount = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == majorityElement) {
                majorityCount++;
            }

            int remainingMajorityCount = totalMajorityCount - majorityCount;
            int leftSize = i + 1;
            int rightSize = n - i - 1;

            if(majorityCount * 2 > leftSize && remainingMajorityCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =========================================================================================
