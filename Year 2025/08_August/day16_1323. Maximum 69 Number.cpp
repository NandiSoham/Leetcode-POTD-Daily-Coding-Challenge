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
