// Problem Link -> https://leetcode.com/problems/most-profit-assigning-work/description/

// --------------------------------- Approach -1  -----------------------------------

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++){
            int diff = difficulty[i];
            int prof = profit[i];
            pq.push({prof, diff});
        }

        sort(worker.begin(), worker.end(), greater<int>());
        int idx = 0;
        int totalProfit = 0;

        while(idx < m && !pq.empty()){
            if(pq.top().second > worker[idx]){
                pq.pop();
            } else {
                totalProfit += pq.top().first;
                idx++;
            }
        }

        return totalProfit;
    }
};


// Time Complexity -> O(nlogn + mlogn)
// Space Complexity -> O(n)

// ----------------------------------------------------------------------------------


// --------------------------------- Approach - 2 -----------------------------------

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i - 1].second);
        }

        int totalProfit = 0;
        for (int i = 0; i < m; i++) {
            int workerDiffLevel = worker[i];
            int maxProfit = 0;
            int low = 0, high = vec.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)

// ----------------------------------------------------------------------------------
