class Solution {
public:
    vector <int> ans;

    void findSequentialNumbers(int low, int high, int i, int num){
        if(num >= low && num <= high){
            ans.push_back(num);
        }
        if(num > high || i > 9){
            return;
        }

        findSequentialNumbers(low, high, i+1, num*10+i);
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++){
            findSequentialNumbers(low, high, i, 0);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// Time Complexity -> O(nlogn)
// Space Complexity - > O(n)
// Problem Link - > https://leetcode.com/problems/sequential-digits/?envType=daily-question&envId=2024-02-03  
