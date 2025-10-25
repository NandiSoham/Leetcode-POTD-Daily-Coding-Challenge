// Problem Link -> https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

class Solution {
public:
    int totalMoney(int n) {
        int moneySum = 0;
        int mondayMoney = 1;  

        while(n > 0){
            int currMoney = mondayMoney;

            for(int day = 1; day <= min(n, 7); day++){
                moneySum += currMoney;
                currMoney++;
            }
            
            n -= 7;           
            mondayMoney++;    
        }

        return moneySum;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
