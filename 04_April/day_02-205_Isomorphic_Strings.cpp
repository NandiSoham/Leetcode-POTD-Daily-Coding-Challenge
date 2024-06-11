class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> first_map;
        unordered_map<char, char> second_map;

        int n = s.length(); // length of s and t are same according to Constraints, so considerlength of anyone of them

        for(int  i = 0; i < n; i++){
            char char_of_s = s[i];
            char char_of_t = t[i];

            if(first_map.find(char_of_s) != first_map.end() && first_map[char_of_s] != char_of_t ||
                second_map.find(char_of_t) != second_map.end() && second_map[char_of_t] != char_of_s){
                    return false;
            }
            first_map[char_of_s] = char_of_t;
            second_map[char_of_t] = char_of_s;
        }
        return true;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/isomorphic-strings/
