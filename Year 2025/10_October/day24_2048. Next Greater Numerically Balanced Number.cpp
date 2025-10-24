// Problem Link -> https://leetcode.com/problems/next-greater-numerically-balanced-number/description/

class Solution {
public:

    bool isBalanced(int num){
        vector<int> freq(10);

        while(num > 0){
            int digit = num % 10;
            freq[digit]++;
            num /= 10;
        }

        for(int i = 0; i < 10 ; i++){
            if(freq[i] > 0 && freq[i] != i){
                return false;
            }
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224444; i++){
            if(isBalanced(i)){
                return i;
            }
        }

        return -1;
    }
};


// Time Complexity -> O((U - n) * d)
// Space complexity -> O(1)
