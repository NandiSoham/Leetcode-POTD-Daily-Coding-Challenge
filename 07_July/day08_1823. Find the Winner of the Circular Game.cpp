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

// ------------------------------------ Approach - 2 -------------------------------------

class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n == 1) {
            return 0; //index
        }

        int idx = findWinnerIdx(n-1, k);
        idx = (idx + k) % n; //to find the original index in the original array

        return idx;
    }

    int findTheWinner(int n, int k) {
        
        int result_idx = findWinnerIdx(n, k);


        return result_idx + 1;

    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------
