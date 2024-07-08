// problem Link -> https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

// ------------------------------------ Approach - 1 -------------------------------------

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friendsArr;
        for(int i = 1; i <= n; i++){
            friendsArr.push_back(i);
        }

        int i = 0;
        while(friendsArr.size() > 1){
            int idx = (i + k - 1) % friendsArr.size();
            friendsArr.erase(friendsArr.begin() + idx);
            i = idx;
        }

        return friendsArr[0];
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------
