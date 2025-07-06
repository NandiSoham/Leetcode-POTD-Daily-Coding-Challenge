// Problem link -> https://leetcode.com/problems/find-lucky-integer-in-an-array/description/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int num : arr) {
            freq[num]++;
        }

        int max_lucky = -1;

        // Check if number == its frequency
        for (auto [num, count] : freq) {
            if (num == count) {
                max_lucky = max(max_lucky, num);
            }
        }

        return max_lucky;
    }
};


