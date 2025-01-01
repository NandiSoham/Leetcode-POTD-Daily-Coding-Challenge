// Problem Link -> https://leetcode.com/problems/reverse-string/description/

// ------------------------------------ Approach - 1 ----------------------------------

class Solution {
public:
    void reverseString(vector<char>& s) {
        return reverse(s.begin(), s.end());
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// ------------------------------------------------------------------------------------

// ------------------------------------ Approach - 2 ----------------------------------

class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftPtr = 0;
        int rightPtr = s.size() - 1;

        while(leftPtr <= rightPtr){
            swap(s[leftPtr], s[rightPtr]);
            leftPtr++;
            rightPtr--;
        }
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
// ------------------------------------------------------------------------------------
