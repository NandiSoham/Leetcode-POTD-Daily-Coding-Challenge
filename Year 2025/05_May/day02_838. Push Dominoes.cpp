// Problem Link -> https://leetcode.com/problems/push-dominoes/description/

class Solution {
public:
    string pushDominoes(string dominoes) {
        string paddedDominoes = "L" + dominoes + "R";
        int n = paddedDominoes.length();
        string ans = "";

        for (int left = 0, right = 1; right < n; right++) {
            if (paddedDominoes[right] == '.')
                continue;

            int midLen = right - left - 1;
            if (left > 0)
                ans.push_back(paddedDominoes[left]);

            if (paddedDominoes[left] == paddedDominoes[right])
                ans += string(midLen, paddedDominoes[left]);
            else if (paddedDominoes[left] == 'L' &&
                     paddedDominoes[right] == 'R')
                ans += string(midLen, '.');
            else
                ans += string(midLen / 2, 'R') +
                       string(midLen % 2, '.') +
                       string(midLen / 2, 'L');

            left = right;
        }

        return ans;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
