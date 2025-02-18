// Problem Link -> https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    bool matchesCondition(string& num, string& pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
                (pattern[i] == 'D' && num[i] < num[i + 1])) {
                return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";

        for (int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0');
        }

        while (!matchesCondition(num, pattern)) {
            next_permutation(num.begin(), num.end());
        }

        return num;
    }
};



// Time Complexity -> O(n * (n+1)!)
// Space Complexity -> O(n + 1)

// ========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        stack<char> charSt;
        int counter = 1;

        for(int i = 0; i <= n; i++){
            charSt.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I'){
                while(!charSt.empty()){
                    num += charSt.top();
                    charSt.pop();
                }
            }
        }

        return num;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// ========================================================================================
