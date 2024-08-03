// Problem Link -> https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

// --------------------------------- Approach - 1 -------------------------------------

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for(int i = 0; i < target.size(); i++){
            if(target[i] != arr[i]) return false;
        }

        return true;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(1)

// ---------------------------------------------------------------------------------------


// --------------------------------- Approach - 2 -------------------------------------

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freqMap;

        for(int &num : target){
            freqMap[num]++;
        }

        for(int &it : arr){
            if(freqMap.find(it) == freqMap.end()) return false;

            freqMap[it]--;
            if(freqMap[it] == 0)
                freqMap.erase(it);
        }

        return freqMap.size() == 0;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// ---------------------------------------------------------------------------------------
