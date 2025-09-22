// Problem Link -> https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);  

        int maxfreq = 0;  
        int result = 0;   

        for (int it : nums) {
            freq[it]++;  

            if (freq[it] > maxfreq) {
                maxfreq = freq[it];
                result = freq[it];    
            } 
            else if (freq[it] == maxfreq) {
                result += freq[it];  
            }
        }

        return result;
    }
};


// Time Complexity -> O(n)
// Space complexity -> O(1)
