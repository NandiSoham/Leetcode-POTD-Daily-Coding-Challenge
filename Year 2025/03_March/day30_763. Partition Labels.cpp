// Problem Link -> https://leetcode.com/problems/partition-labels/description/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> partitions;

        vector<int> lastOccurr(26, -1);
        for(int i = 0; i < n; i++) {
            int charIdx = s[i] - 'a';
            lastOccurr[charIdx] = i;
        }

        int idx = 0;
        int segmentStart = 0;
        int segmentEnd = 0;
        while(idx < n) {
            segmentEnd = max(segmentEnd, lastOccurr[s[idx] - 'a']);
            if(idx == segmentEnd) {
                partitions.push_back(segmentEnd - segmentStart + 1);
                segmentStart = segmentEnd + 1;
            }
            idx++;
        }

        return partitions;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
