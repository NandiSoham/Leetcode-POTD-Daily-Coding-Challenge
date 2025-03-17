// Problem Link -> https://leetcode.com/problems/divide-array-into-equal-pairs/description/

// ======================================= Approach - 1 (Sorting) ====================================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i+= 2){
            if(nums[i] != nums[i + 1]){
                return false;
            }
        }

        return true;
    }
};


// Time Complexity -> O(n logn)
// Space Complexity -> O(1)

// =============================================================================================================


// ============================================= Approach - 2 (Map) ============================================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for(int num : nums){
            freqMap[num]++;
        }

        for(auto it : freqMap){
            if(it.second % 2 != 0){
                return false;
            }
        }

        return true;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =============================================================================================================


// ======================================= Approach - 3 (Bit Manipulation) =====================================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int maxNum = 0;
        for(int num : nums){
            maxNum = max(maxNum, num);
        }

        vector<bool> pairCheck(maxNum + 1, false);
        for(int num : nums){
            pairCheck[num] = !pairCheck[num];
        }

        for(int num : nums){
            if(pairCheck[num] == true){
                return false;
            }
        }

        return true;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(maxNum)

// =============================================================================================================


// =============================================== Approach - 4 (Set) ==========================================

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> pairCheckSet;

        for(int num : nums){
            if(pairCheckSet.count(num)){
                pairCheckSet.erase(num);
            } else {
                pairCheckSet.insert(num);
            }
        }

        return pairCheckSet.empty();
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)

// =============================================================================================================
