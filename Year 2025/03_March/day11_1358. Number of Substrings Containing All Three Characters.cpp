// Problem Link -> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// ======================================= Approach - 1 (TLE) ====================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int subStrCount = 0;

        for(int i = 0; i < n; i++){
            int charPresent[3] = {0};

            for(int j = i; j < n; j++){
                charPresent[s[j] - 'a'] = 1;

                if(charPresent[0] + charPresent[1] + charPresent[2] == 3){
                    subStrCount++;
                }
            }
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 (TLE) ====================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int subStrCount = 0;

        for(int i = 0; i < n; i++){
            int charPresent[3] = {0};

            for(int j = i; j < n; j++){
                charPresent[s[j] - 'a'] = 1;

                if(charPresent[0] + charPresent[1] + charPresent[2] == 3){
                    subStrCount += n - j;
                    break;
                }
            }
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n^2)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 3 ====================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeenIdx[3] = {-1, -1, -1};
        int subStrCount = 0;

        for(int i = 0; i < s.size(); i++) {
            lastSeenIdx[s[i] - 'a'] = i;

            if(lastSeenIdx[0] != -1 && lastSeenIdx[1] != -1 && lastSeenIdx[2] != -1){
                subStrCount += 1 + min({lastSeenIdx[0], lastSeenIdx[1], lastSeenIdx[2]});
            }
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 4 ====================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int subStrCount = 0;
        vector<int> charFreq(3, 0);
        int i = 0, j = 0;

        while(j < n) {
            char currChar = s[j];
            charFreq[currChar - 'a']++;

            while(charFreq[0] > 0 && charFreq[1] > 0 && charFreq[2] > 0) {
                subStrCount += n - j;
                charFreq[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n)
// SPace Complexity -> O(1)

// =========================================================================================
