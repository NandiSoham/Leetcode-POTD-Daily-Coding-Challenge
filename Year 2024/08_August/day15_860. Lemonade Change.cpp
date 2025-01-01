// Problem Link -> https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeFive = 0;
        int changeTen = 0;
        int n = bills.size();

        for(int i = 0; i < n; i++){
            if(bills[i] == 5) changeFive++;
            else if(bills[i] == 10){
                if(changeFive > 0){
                    changeFive--;
                    changeTen++;
                } else return false;
            } else{
                if(changeFive > 0 && changeTen > 0){
                    changeFive--;
                    changeTen--;
                } else if(changeFive >= 3) changeFive -= 3;
                else return false;
            }
        }
        return true;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
