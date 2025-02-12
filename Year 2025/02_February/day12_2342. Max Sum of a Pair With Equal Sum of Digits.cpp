// Problem Link -> https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/

// ======================================= Approach - 1 (TLE) ====================================

class Solution {
public:
    int findDigSum(int num){
        int sum = 0; 

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int digSum_i = findDigSum(nums[i]);

            for (int j = i + 1; j < n; j++) {
                int digSum_j = findDigSum(nums[j]);

                if(digSum_i == digSum_j){
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }

        return ans;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int findDigSum(int num){
        int sum = 0; 

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, int> sumToNumMap;

        for(int i = 0; i < n; i++){
            int digSum = findDigSum(nums[i]);

            if(sumToNumMap.count(digSum)){
                ans = max(ans, nums[i] + sumToNumMap[digSum]);
            }
            sumToNumMap[digSum] = max(sumToNumMap[digSum], nums[i]);
        }

        return ans;
    }
};



// Time Complexity -> O(n * k) k = number of digits
// Space Complexity -> O(n)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    int findDigSum(int num){
        int sum = 0; 

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int sumToNumArr[82] = {0};

        for(int i = 0; i < n; i++){
            int digSum = findDigSum(nums[i]);

            if(sumToNumArr[digSum] > 0){
                ans = max(ans, nums[i] + sumToNumArr[digSum]);
            }
            sumToNumArr[digSum] = max(sumToNumArr[digSum], nums[i]);
        }

        return ans;
    }
};



// Time Complexity -> O(n * k) k = number of digits
// Space Complexity -> O(1)

// =========================================================================================
