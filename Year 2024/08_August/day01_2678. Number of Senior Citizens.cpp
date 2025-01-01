// Problem Link -> https://leetcode.com/problems/number-of-senior-citizens/description/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int countSeniorCitizen = 0;
        for(int i = 0; i < details.size(); i++){
            int age = stoi(details[i].substr(11, 2));

            if(age > 60) countSeniorCitizen++;
        }

        return countSeniorCitizen;
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O(1)
