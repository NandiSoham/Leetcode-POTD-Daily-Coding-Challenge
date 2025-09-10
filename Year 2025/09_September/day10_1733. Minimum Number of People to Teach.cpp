// Problem link -> https://leetcode.com/problems/minimum-number-of-people-to-teach/description/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> usersNeedingHelp;

        for (auto& relation : friendships) {
            int personA = relation[0] - 1; 
            int personB = relation[1] - 1;

            unordered_set<int> langsA(languages[personA].begin(), languages[personA].end());
            bool canTalk = false;

            for (int lang : languages[personB]) {
                if (langsA.count(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                usersNeedingHelp.insert(personA);
                usersNeedingHelp.insert(personB);
            }
        }

        vector<int> langCount(n + 1, 0);
        int maxCommonLang = 0;

        for (int user : usersNeedingHelp) {
            for (int lang : languages[user]) {
                langCount[lang]++;
                maxCommonLang = max(maxCommonLang, langCount[lang]);
            }
        }

        return usersNeedingHelp.size() - maxCommonLang;
    }
};



// Time Complexity > O(F × L + U × L)
// Space Complexity -> O(U + N)
