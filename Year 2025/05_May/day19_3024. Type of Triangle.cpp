// Problem Link -> https://leetcode.com/problems/type-of-triangle/description/

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if((a + b > c) && (b + c > a) && (c + a > b)){
            if(a == b && b == c) return "equilateral";
            else if (a == b || b == c || c == a) return "isosceles";
            else return "scalene";
        } 
        
        else return "none";
    }
};


// Time Complexity -> O(1)
// SPace Complexity ->O(1)
