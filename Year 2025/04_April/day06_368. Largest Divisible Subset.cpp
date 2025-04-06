class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> subsetLen(n, 1);
        vector<int> prevLen(n, -1);
        int endIndex = 0;
        int maxLength = 1;

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0) {
                    if(subsetLen[i] < subsetLen[prev] + 1) {
                        subsetLen[i] = subsetLen[prev] + 1;
                        prevLen[i] = prev;
                    }

                    if(subsetLen[i] > maxLength) {
                        maxLength = subsetLen[i];
                        endIndex = i;
                    }
                }
            }
        }

        vector<int> result;
        while(endIndex >= 0) {
            result.push_back(nums[endIndex]);
            endIndex = prevLen[endIndex];
        }

        return result;
    }
};
