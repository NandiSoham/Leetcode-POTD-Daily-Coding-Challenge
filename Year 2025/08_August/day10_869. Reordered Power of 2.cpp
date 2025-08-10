// Problem Link -> https://leetcode.com/problems/reordered-power-of-2/description/

class Solution {
public:
    vector<int> countDigitFreq(int n){
        vector<int> freq(10, 0);

        while(n){
            freq[n % 10]++;
            n = n/10;
        }

        return freq;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> input = countDigitFreq(n);

        for(int power = 0; power <= 29; power++){
            if(input == countDigitFreq(1 << power)){
                return true;
            }
        }

        return false;
    }
};


// Time Complexity -> O(1)
// Space Complexity -> O(1)
