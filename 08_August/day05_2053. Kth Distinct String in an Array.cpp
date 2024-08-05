// Problem Link -> https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map <string, int> stringFreq;

        for(string &s : arr){
            stringFreq[s]++;
        }

        int count = 0;
        for(string &s : arr){
            if(stringFreq[s] == 1) count++;

            if(count == k) return s;
        }

        return "";
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
