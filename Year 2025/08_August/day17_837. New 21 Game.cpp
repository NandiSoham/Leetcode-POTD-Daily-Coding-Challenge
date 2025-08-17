// Problem Link -> https://leetcode.com/problems/new-21-game/description/

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> prob(n + 1, 0.0);
        prob[0] = 1.0;
        double windowSum = (k > 0 ? 1.0 : 0.0); 
        
        for (int score = 1; score <= n; score++) {
            
            prob[score] = windowSum / maxPts;
            
            if (score < k) {
                windowSum += prob[score];
            }
            
            if (score - maxPts >= 0 && score - maxPts < k) {
                windowSum -= prob[score - maxPts];
            }
        }
        
        return accumulate(prob.begin() + k, prob.end(), 0.0);
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
