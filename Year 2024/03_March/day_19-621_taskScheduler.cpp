class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxFreq = count[25];
        int idle = (maxFreq - 1) * n;
        for (int i = 24; i >= 0; i--) {
            idle -= min(maxFreq - 1, count[i]);
        }
        idle = max(0, idle);
        return tasks.size() + idle;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/task-scheduler/
