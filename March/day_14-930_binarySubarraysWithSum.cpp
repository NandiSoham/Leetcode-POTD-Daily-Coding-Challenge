class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sumCount; 
        int count = 0;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;

            if (currentSum == goal) {
                count++;
            }

            if (sumCount.count(currentSum - goal) > 0) { 
                count += sumCount[currentSum - goal];
            }
            sumCount[currentSum]++;
        }

        return count;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
