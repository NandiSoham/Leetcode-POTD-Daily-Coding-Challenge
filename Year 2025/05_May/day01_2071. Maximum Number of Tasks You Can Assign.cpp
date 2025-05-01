// Problem Link -> https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

class Solution {
public:
    bool canAssignTasks(vector<int>& tasks, vector<int>& workers, int pills,
               int strength, int mid) {

        int pillsUsed = 0;
        multiset<int> availableWorkers(begin(workers), begin(workers) + mid);

        for (int i = mid - 1; i >= 0; i--) {
            int requiredStrength = tasks[i];
            auto strongestWorkerIt = prev(availableWorkers.end());

            if (*strongestWorkerIt >= requiredStrength) {
                availableWorkers.erase(strongestWorkerIt);
            } else if (pillsUsed >= pills) {
                return false;
            } else {
                auto boostedWorkerIt =
                    availableWorkers.lower_bound(requiredStrength - strength);
                if (boostedWorkerIt == availableWorkers.end()) {
                    return false;
                }
                availableWorkers.erase(boostedWorkerIt);
                pillsUsed++;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int taskCount = tasks.size();
        int workerCount = workers.size();

        int left = 0;
        int right = min(taskCount, workerCount);

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int maxAssignable = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canAssignTasks(tasks, workers, pills, strength, mid)) {
                maxAssignable = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return maxAssignable;
    }
};



// Time Complexity -> O(MLogM+NLogN+Min(M,N)∗Log(Min(M,N))∗Log(Min(M,N))), M = tasks.size(), N = workers.size()
// Space Complexity -> O(N + M)
