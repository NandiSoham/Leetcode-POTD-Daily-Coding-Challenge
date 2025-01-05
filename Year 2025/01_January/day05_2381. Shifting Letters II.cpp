// Problem Link -> https://leetcode.com/problems/shifting-letters-ii/description/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftArr(n, 0);

        for(auto &item : shifts){
            int leftIdx = item[0];
            int rightIdx = item[1];
            int direction = item[2];
            int val;

            if(direction == 0) val = -1;
            else val = 1;

            shiftArr[leftIdx] += val;
            if(rightIdx + 1 < n)
                shiftArr[rightIdx + 1] -= val;
        }

        for(int i = 1; i < n; i++){
            shiftArr[i] += shiftArr[i - 1];
        }

        for(int i = 0; i < n; i++){
            int netShift = shiftArr[i] % 26;
            if(netShift < 0) netShift += 26;

            s[i] = ((((s[i] - 'a') + netShift) % 26) + 'a');
        }

        return s;
    }
};



// Time Complexity -> O(Q + N) [Q = size of queries; N = size of the aray]
// Space Complexity -> O(n)
