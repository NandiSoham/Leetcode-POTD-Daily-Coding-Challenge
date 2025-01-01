// Problem Link -> https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> remCountMap;
        remCountMap[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remainder = sum % k;

            if(remainder < 0){
                remainder += k;
            }

            if(remCountMap.find(remainder) != remCountMap.end()){
                ans += remCountMap[remainder];
            }
            remCountMap[remainder]++;
        }
        
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
