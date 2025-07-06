// Problem Link -> https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

class FindSumPairs {
public:
    vector<int> nums1Copy, nums2Copy;
    unordered_map<int, int> freqMap;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums1Copy = nums1;
        nums2Copy = nums2;
        for (int &num : nums2Copy) {
            freqMap[num]++;
        }
    }
    
    void add(int index, int val) {
        freqMap[nums2Copy[index]]--;
        nums2Copy[index] += val;
        freqMap[nums2Copy[index]]++;
    }
    
    int count(int tot) {
        int totalPairs = 0;
        for (int &num : nums1Copy) {
            totalPairs += freqMap[tot - num];
        }
        return totalPairs;
    }
};
