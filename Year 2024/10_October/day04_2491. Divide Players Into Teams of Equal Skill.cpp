// Problem Link -> https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        
        sort(begin(skill), end(skill));

        int left = 0;
        int right = n - 1;
        int targetSkillSum = skill[left] + skill[right]; 

        long long totalChemistry = 0;

        while (left < right) {
            int currentSkillSum = skill[left] + skill[right];

            if (currentSkillSum != targetSkillSum) {
                return -1;
            }

            totalChemistry += (long long)skill[left] * (long long)skill[right];

            left++;
            right--;
        }
        
        return totalChemistry;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
