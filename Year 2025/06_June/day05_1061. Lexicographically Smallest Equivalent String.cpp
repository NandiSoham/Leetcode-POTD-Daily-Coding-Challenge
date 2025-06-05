// Problem Link -> https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

class Solution {
public:
    char getMinCharDFS(char currChar, vector<int> &isVisited,
                       unordered_map<char, vector<char>> &adjList) {
        
        isVisited[currChar - 'a'] = 1;
        char minChar = currChar;

        for(char &ch : adjList[currChar]){
            if(isVisited[ch - 'a'] == 0){
                minChar = min(minChar, getMinCharDFS(ch, isVisited, adjList));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        unordered_map<char, vector<char>> adjList;
        string ans;

        for (int i = 0; i < n; i++) {
            char charA = s1[i];
            char charB = s2[i];

            adjList[charA].push_back(charB);
            adjList[charB].push_back(charA);
        }

        for (int i = 0; i < m; i++) {
            char ch = baseStr[i];
            vector<int> isVisited(26, 0);

            ans.push_back(getMinCharDFS(ch, isVisited, adjList));
        }

        return ans;
    }
};


//Time Complexity -> O(m* ( charA + charB))
//Space Complexity -> ( charA + charB)
