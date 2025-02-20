// Problem Link -> https://leetcode.com/problems/find-unique-binary-string/description/

// ======================================= Approach - 1 ====================================

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        unordered_set<int> strSet;

        for (string& num : nums) {
            strSet.insert(stoi(num, 0, 2));
        }

        

        for (int number = 0; number <= 65536; number++) {

            if (strSet.find(number) == strSet.end()) {
                ans = bitset<16>(number).to_string();
                break;
            }
        }

        return ans.substr(16 - n);
    }
};



// Time Complexity ->O(n^2)
// Space Complexity -> O(n)

// ========================================================================================
