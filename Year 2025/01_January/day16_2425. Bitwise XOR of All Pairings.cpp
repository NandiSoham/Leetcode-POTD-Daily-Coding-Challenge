// Problem Link -> https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, long> freqMap;
        int result = 0;

        for(int& num : nums1){
            freqMap[num] += m;
        }

        for(int& num : nums2){
            freqMap[num] += n;
        }

        for(auto& element : freqMap){
            int num = element.first;
            int freq = element.second;

            if(freq % 2 != 0){
                result ^= num;
            }
        }

        return result;
    }
};



// Time Complexity -> O(n + m)
// Space Complexity -> O(n + m)

// =========================================================================================
