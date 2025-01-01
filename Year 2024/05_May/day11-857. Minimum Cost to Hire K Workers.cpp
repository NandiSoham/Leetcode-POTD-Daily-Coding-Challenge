// Problem Link -> https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        double ans = DBL_MAX;
        vector<pair<double, int>> worker_ratio(n);

        for (int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)wage[worker] / quality[worker], quality[worker]);
        }

        sort(worker_ratio.begin(), worker_ratio.end());
        priority_queue<int, vector<int>> worker_que;
        int quality_sum = 0;

        for(int i = 0; i < k; i++){
            worker_que.push(worker_ratio[i].second);
            quality_sum += worker_ratio[i].second;
        }

        double manager_ratio = worker_ratio[k-1].first;
        ans = manager_ratio * quality_sum;

        for (int manager = k; manager < n; manager++) {
            double manager_ratio = (double)worker_ratio[manager].first;
            worker_que.push(worker_ratio[manager].second);
            quality_sum += worker_ratio[manager].second;
            
            if(worker_que.size() > k){
                quality_sum -= worker_que.top();
                worker_que.pop();
            }
            ans = min(ans, (quality_sum * manager_ratio));
        }

        return ans;
    }
};



// Time Complexity -> O(nlogn + klogk + n*log(k))
// Space Complexity -> O(n+k)
