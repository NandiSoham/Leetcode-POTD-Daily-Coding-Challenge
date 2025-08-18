// Problem Link -> https://leetcode.com/problems/24-game/description/

class Solution {
public:
    double tolerance = 0.1;

    bool canMake24(vector<double> &nums){
        if(nums.size() == 1){
            return abs(nums[0] - 24.0) <= tolerance;
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <nums.size(); j++){
                if(i == j) continue;

                vector<double> remaining;
                for(int k = 0; k < nums.size(); k++){
                    if(k != i && k != j) remaining.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];
                vector<double> possibleOps = {a+b, a-b, b-a, a*b};

                if(abs(a) > 0.0) possibleOps.push_back(b/a);
                if(abs(b) > 0.0) possibleOps.push_back(a/b);

                for(double &it : possibleOps){
                    remaining.push_back(it);
                    if(canMake24(remaining)) return true;
                    remaining.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int &it : cards){
            nums.push_back(it);
        }

        return canMake24(nums);
    }
};



// Time complexity -> O(1)
// Space Compelxity -> O(1)
