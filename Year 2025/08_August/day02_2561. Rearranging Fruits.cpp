class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freqDiff;
        int smallestElement = INT_MAX;

        for (int& fruit : basket1) {
            freqDiff[fruit]++;
            smallestElement = min(smallestElement, fruit);
        }

        for (int& fruit : basket2) {
            freqDiff[fruit]--;
            smallestElement = min(smallestElement, fruit);
        }

        vector<int> swapCandidates;
        for (auto& entry : freqDiff) {
            int fruitType = entry.first;
            int imbalance = entry.second;

            if (imbalance == 0)
                continue;
            if (imbalance % 2 != 0)
                return -1;

            for (int count = 0; count < abs(imbalance) / 2; ++count) {
                swapCandidates.push_back(fruitType);
            }
        }

        nth_element(swapCandidates.begin(),
                    swapCandidates.begin() + swapCandidates.size() / 2,
                    swapCandidates.end());

        long long minTotalCost = 0;
        for (int i = 0; i < swapCandidates.size() / 2; ++i) {
            minTotalCost += min(swapCandidates[i], 2 * smallestElement);
        }

        return minTotalCost;
    }
};
