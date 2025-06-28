// Problem link -> https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> idxAndElementArr(n);
        vector<int> ansArr(k);

        for(int i = 0; i < n; i++){
            idxAndElementArr[i] = make_pair(i, nums[i]);
        }

        auto lambda = [](auto &p1, auto &p2){
            return p1.second > p2.second;
        };

        sort(idxAndElementArr. begin(), idxAndElementArr.end(), lambda);
        sort(idxAndElementArr.begin(), idxAndElementArr.begin() + k);

        for(int i = 0; i < k; i++){
            ansArr[i] = idxAndElementArr[i].second;
        }

        return ansArr;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
