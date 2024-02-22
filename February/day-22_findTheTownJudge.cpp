class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustee(n + 1);
        vector<int> trusted(n + 1);

        for(vector<int> &pair : trust){
            trustee[pair[0]]++;
            trusted[pair[1]]++;
        }

        for(int i = 1; i < n + 1; i++){
            if(trustee[i] == 0 && trusted[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(2n) ~ O(n)
// Problem link -> https://leetcode.com/problems/find-the-town-judge/description/
