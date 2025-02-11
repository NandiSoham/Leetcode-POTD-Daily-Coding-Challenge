// Problem Link -> https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};



// Time Complexity -> O(m*n)
// Space COmplexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:

    bool checkFunc(stack<char>& charSt, string& part, int n){
        stack<char> tempSt = charSt;

        for(int i = n - 1; i >= 0; i--){
            if(tempSt.top() != part[i]){
                return false;
            }
            tempSt.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> charSt;
        int m = s.length();
        int n = part.length();
        string result = "";

        for(int i = 0; i < m; i++){
            charSt.push(s[i]);

            if(charSt.size() >= n && checkFunc(charSt, part, n) == true){
                for(int j = 0; j < n; j++){
                    charSt.pop();
                }
            }
        }

        while(!charSt.empty()){
            result.push_back(charSt.top());
            charSt.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};



// Time Complexity -> O(m*n)
// Space COmplexity -> O(m)

// =========================================================================================
