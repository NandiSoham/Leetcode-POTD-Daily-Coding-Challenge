// Problem Link -> https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ansArr;  

        for(int it : nums){
            
            while(!ansArr.empty()){
                int prevNum = ansArr.back();
                
                int GCD = gcd(it, prevNum);
                if(GCD == 1) break;  
                
                ansArr.pop_back();
                long long LCM = (1LL * it * prevNum) / GCD;
                
                it = LCM;  
            }
            
            ansArr.push_back(it);  
        }

        return ansArr;
    }
};


// Time complexity -> O(n × log(m))    [m = max(it, prevNum)]
// Space complexity -> O(n)
