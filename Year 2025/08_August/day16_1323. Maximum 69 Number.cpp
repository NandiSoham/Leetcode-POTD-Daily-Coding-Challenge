// Problem link -> https://leetcode.com/problems/maximum-69-number/description/

// ================================== Approach - 1 ==================================

class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);

        for(char &ch : str){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }

        return stoi(str);
    }
};


// Time Complexity -> O(d)
// Space Complexity -> O(1)

// ==================================================================================


// ================================== Approach - 2 ==================================

class Solution {
public:
    int maximum69Number (int num) {
        int digitPos = 0;
        int leftMostSixPos = -1;
        int temp = num;

        while(temp > 0){
            int remainder = temp % 10;

            if(remainder == 6){
                leftMostSixPos = digitPos;
            }

            temp /= 10;
            digitPos++;
        }

        if(leftMostSixPos == -1) return num;

        return num + 3*pow(10, leftMostSixPos);
    }
};


// Time Complexity -> O(d)
// Space Complexity -> O(1)

// ==================================================================================
