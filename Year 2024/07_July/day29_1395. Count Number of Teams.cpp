// Problem Link -> https://leetcode.com/problems/count-number-of-teams/description/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teamCount = 0;

        for(int j = 1; j < n - 1; j++){
            int smallerLeftCount = 0;
            int largerLeftCount = 0;
            int smallerRightCount = 0;
            int largerRightCount = 0;

            for(int i = 0; i < j; i++){
                if (rating[i] < rating[j]) smallerLeftCount++;
                else if(rating[i] > rating[j]) largerLeftCount++;
            }

            for(int k = j + 1; k < n; k++){
                if (rating[k] < rating[j]) smallerRightCount++;
                else if(rating[k] > rating[j]) largerRightCount++;
            }

            teamCount += (smallerLeftCount * largerRightCount) + (smallerRightCount * largerLeftCount);
        }

        return teamCount;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)
