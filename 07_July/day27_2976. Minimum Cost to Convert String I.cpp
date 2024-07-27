// Problem Link -> https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution {
public:
    void FloydWarshall(vector<vector<long long>> &distanceMatrix, vector<char>& originalChars, vector<char>& changedChars, vector<int>& conversionCosts) {

            for(int i = 0; i < originalChars.size(); i++) {
                int sourceChar = originalChars[i] - 'a';
                int targetChar = changedChars[i] - 'a';

                distanceMatrix[sourceChar][targetChar] = min(distanceMatrix[sourceChar][targetChar], (long long)conversionCosts[i]);
            }

            for (int intermediate = 0; intermediate < 26; ++intermediate) {
                for (int start = 0; start < 26; ++start) {
                    for (int end = 0; end < 26; ++end) {
                        distanceMatrix[start][end] = min(distanceMatrix[start][end], distanceMatrix[start][intermediate] + distanceMatrix[intermediate][end]); 
                    }
                }
            } 
    }

    long long minimumCost(string startString, string endString, vector<char>& originalChars, vector<char>& changedChars, vector<int>& conversionCosts) {
        vector<vector<long long>> distanceMatrix(26, vector<long long>(26, INT_MAX));

        FloydWarshall(distanceMatrix, originalChars, changedChars, conversionCosts); 

        long long totalCost = 0;

        for(int i = 0; i < startString.length(); i++) {
            if(startString[i] == endString[i]) {
                continue;
            }

            if(distanceMatrix[startString[i] - 'a'][endString[i] - 'a'] == INT_MAX) {
                return -1;
            }

            totalCost += distanceMatrix[startString[i] - 'a'][endString[i] - 'a'];
        }

        return totalCost;
    }
};




// Time Complexity -> O(n)
// Space Complexity -> O(1)
