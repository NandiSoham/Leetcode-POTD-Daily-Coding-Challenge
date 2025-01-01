// Problem Link -> https://leetcode.com/problems/relative-sort-array/description/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freqMap;

        for(auto &num : arr1){
            freqMap[num]++;
        }

        int idx = 0;
        for(auto &num : arr2){
            while(freqMap[num]-- > 0){
                arr1[idx++] = num;
            }
        }

        for(auto &it : freqMap){
            int freq = it.second;
            while(freq > 0){
                arr1[idx++] = it.first;
                freq--;
            }
        }

        return arr1;
    }
};


// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
