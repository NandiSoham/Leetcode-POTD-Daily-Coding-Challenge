// Problem Link -> https://leetcode.com/problems/three-consecutive-odds/description/

// ----------------------------------------- Approach - 1 ----------------------------------------

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 != 0) count++;
            else count = 0;

            if(count == 3) return true;
        }

        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity ->O(1)

// -----------------------------------------------------------------------------------------------

// ----------------------------------------- Approach - 2 ----------------------------------------

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for(int i = 0; i < arr.size() - 2; i++){
            if(arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0){
                return true;
            }
        }
        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity ->O(1)

// -----------------------------------------------------------------------------------------------
