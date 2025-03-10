// Problem Link -> https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/

class Solution {
public:
    bool checkVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }
    
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> vowelMap;
        vector<int> constIdx(n);
        int lastConstPos = n;

        for (int i = n - 1; i >= 0; i--) {
            constIdx[i] = lastConstPos;

            if (!checkVowel(word[i])) {
                lastConstPos = i;
            }
        }

        int left = 0, right = 0;
        long long subStrCount = 0;
        int constCount = 0;

        while (right < n) {
            char ch = word[right];

            if (checkVowel(ch)) vowelMap[ch]++;
            else constCount++;

            while (constCount > k) {
                char ch = word[left];

                if (checkVowel(ch)) {
                    vowelMap[ch]--;
                    if (vowelMap[ch] == 0) {
                        vowelMap.erase(ch);
                    }
                } else {
                    constCount--;
                }
                left++;
            }

            while (left < n && vowelMap.size() == 5 && constCount == k) {
                int nextIndex = constIdx[right];
                subStrCount += nextIndex - right;
                char ch = word[left];

                if (checkVowel(ch)) {
                    vowelMap[ch]--;
                    if (vowelMap[ch] == 0) {
                        vowelMap.erase(ch);
                    }
                } else {
                    constCount--;
                }
                left++;
            }

            right++;
        }

        return subStrCount;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
