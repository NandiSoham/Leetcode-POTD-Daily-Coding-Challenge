// Problem Link -> https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/

class Solution {
public:
    long long currentSum = 0;
    set<pair<int, int>> topGroup;     
    set<pair<int, int>> restGroup;    

    void addPair(const pair<int, int>& p, int x) {
        if (topGroup.size() < x || p > *topGroup.begin()) {
            currentSum += 1LL * p.first * p.second;
            topGroup.insert(p);

            if (topGroup.size() > x) {
                auto smallest = *topGroup.begin();
                currentSum -= 1LL * smallest.first * smallest.second;
                topGroup.erase(smallest);
                restGroup.insert(smallest);
            }
        } else {
            restGroup.insert(p);
        }
    }

    void removePair(const pair<int, int>& p, int x) {
        if (topGroup.find(p) != topGroup.end()) {
            currentSum -= 1LL * p.first * p.second;
            topGroup.erase(p);

            if (!restGroup.empty()) {
                auto largest = *restGroup.rbegin();
                restGroup.erase(largest);
                topGroup.insert(largest);
                currentSum += 1LL * largest.first * largest.second;
            }
        } else {
            restGroup.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        currentSum = 0;
        vector<long long> result;
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        while (right < n) {
            if (freq[nums[right]] > 0) {
                removePair({freq[nums[right]], nums[right]}, x);
            }

            freq[nums[right]]++;
            addPair({freq[nums[right]], nums[right]}, x);

            if (right - left + 1 == k) {
                result.push_back(currentSum);

                removePair({freq[nums[left]], nums[left]}, x);
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                } else {
                    addPair({freq[nums[left]], nums[left]}, x);
                }
                left++;
            }

            right++;
        }

        return result;
    }
};


// Time Complexity -> O(n log m)
// Space Complexity -> O(m)

// where m = unique elemnets
