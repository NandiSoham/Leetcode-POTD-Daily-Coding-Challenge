// Problem Link -> https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

// ======================================= Approach - 1 (TLE issue) ====================================

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (true) {
                int smallerVal = nums[i];
                int idx = -1;

                for (int j = i + 1; j < n; j++) {
                    if (abs(nums[i] - nums[j]) <= limit && nums[j] < smallerVal) {
                        smallerVal = nums[j];
                        idx = j;
                    }
                }

                if (idx != -1) {
                    swap(nums[i], nums[idx]);
                } else break;
            }
        }

        return nums;
    }
};



// Time Complexity -> O(n^3)
// Space Complexity -> O(1)

// =========================================================================================

// ======================================= Approach - 2 ====================================

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int currentGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[sortedNums[0]] = currentGroup;

        unordered_map<int, list<int>> groupToElements;
        groupToElements[currentGroup].push_back(sortedNums[0]);

        for (int i = 1; i < n; i++) {
            if (abs(sortedNums[i] - sortedNums[i - 1]) > limit) {
                currentGroup++;
            }

            numToGroup[sortedNums[i]] = currentGroup;
            groupToElements[currentGroup].push_back(sortedNums[i]);
        }

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToElements[group].begin();
            groupToElements[group].pop_front();
        }

        return nums;
    }
};



// Time Complexity -> O(n*logn)
// Space Complexity -> O(n)

// =========================================================================================
