// Prblem Link -> https://leetcode.com/problems/relative-ranks/description/

// ---------------------------------------- Approach - 1 ---------------------------------------

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> scoreMap;

        for(int i = 0; i < n; i++){
            scoreMap[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        for(int i = 0; i < n; i++){
            if(i == 0){
                int athlete = scoreMap[score[i]];
                ans[athlete] = "Gold Medal";
            }
            else if(i == 1){
                int athlete = scoreMap[score[i]];
                ans[athlete] = "Silver Medal";
            }
            else if(i == 2){
                int athlete = scoreMap[score[i]];
                ans[athlete] = "Bronze Medal";
            }
            else{
                int athlete = scoreMap[score[i]];
                ans[athlete] = to_string(i+1);
            } 
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------


// ---------------------------------------- Approach - 2 ---------------------------------------

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        int maxScore = *max_element(score.begin(), score.end());
        vector<int> athleteArr(maxScore + 1, -1);

        for (int i = 0; i < n; i++) {
            athleteArr[score[i]] = i;
        }

        int rank = 1;
        for (int scr = maxScore; scr >= 0; scr--) { // backward traversing
            if (athleteArr[scr] != -1) {
                int athlete = athleteArr[scr];

                if (rank == 1)
                    ans[athlete] = "Gold Medal";
                else if (rank == 2)
                    ans[athlete] = "Silver Medal";
                else if (rank == 3)
                    ans[athlete] = "Bronze Medal";
                else
                    ans[athlete] = to_string(rank);
                
                rank++;
            }
        }
        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(maxScore)

//-----------------------------------------------------------------------------------------------
