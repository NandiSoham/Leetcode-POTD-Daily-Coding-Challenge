// Problem Link -> https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> increasingSeq;  
        int totalOps = 0;         

        for (int num : nums) {

            while (!increasingSeq.empty() && increasingSeq.top() > num) {
                increasingSeq.pop();
            }

            if (num == 0) continue;

            if (increasingSeq.empty() || increasingSeq.top() < num) {
                increasingSeq.push(num);
                totalOps++;
            }
        }

        return totalOps;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
