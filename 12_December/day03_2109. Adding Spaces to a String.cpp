class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spaceIndex = 0;
        int totalSpaces = spaces.size();

        for (int i = 0; i < s.length(); i++) {
            if (spaceIndex < totalSpaces && i == spaces[spaceIndex]) {
                result += " ";
                spaceIndex++;
            }
            result += s[i];
        }

        return result;
    }
};
