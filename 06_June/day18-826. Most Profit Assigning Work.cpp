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
