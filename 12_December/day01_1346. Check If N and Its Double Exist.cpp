// Problem Link -> https://leetcode.com/problems/check-if-n-and-its-double-exist/description/

class Solution {
public:
    bool checkIfExist(vector<int>& numbers) {
        unordered_set<int> seenNumbers;

        for (int current : numbers) {
            if (seenNumbers.find(current * 2) != seenNumbers.end()) {
                return true;
            } 
            if (current % 2 == 0 && seenNumbers.find(current / 2) != seenNumbers.end()) {
                return true;
            }
            seenNumbers.insert(current);
        }

        return false;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
