// Problem link -> https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int sum = 0;
        int sqSum = 0;

        for (int i : nums) {
            sum += i;
            sqSum += i*i;
        }

        int a = sum - (n * (n - 1)) / 2;
        int b = sqSum - ((n - 1) * (n) * (2 * n - 1)) / 6;
        int c = (a * a - b) / 2;

        int x = (a + sqrt(a * a - 4 * c)) / 2;
        int y = (a - sqrt(a * a - 4 * c)) / 2;

        return {x, y};
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)
