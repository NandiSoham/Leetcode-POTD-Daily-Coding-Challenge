// ------------------------------ Approach - 1 with 2 pass -----------------------------------

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101);
        int maxFreq = 0;
        int ans = 0;

        for(int &it : nums){
            arr[it]++;
            maxFreq = max(maxFreq, arr[it]);
        }

        for(int i = 0; i < 101; i++){
            if(arr[i] == maxFreq){
                ans += maxFreq;
            }
        }
        return ans;
    }
};


// Time Complexity -> O(n + n)
// Space Complexity -> O(101) ~ O(1)

//--------------------------------------------------------------------------------------------
