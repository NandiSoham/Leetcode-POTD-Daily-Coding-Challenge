// Problem Link -> https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> wizardTime(n, 0); 

        for (int potion = 0; potion < m; ++potion) {
            wizardTime[0] += 1LL * mana[potion] * skill[0];

            for (int i = 1; i < n; ++i){
                wizardTime[i] = max(wizardTime[i], wizardTime[i - 1]) + 1LL * mana[potion] * skill[i];
            }

            for (int i = n - 1; i > 0; --i){
                wizardTime[i - 1] = wizardTime[i] - 1LL * mana[potion] * skill[i];
            }
        }

        return wizardTime[n - 1]; 
    }
};



// Time complexity -> O(m*n)
// Space Complexity -> O(n)
