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


// ======================================= Better of Approach - 1 ====================================

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        unordered_set<int> strSet;

        for (string& num : nums) {
            strSet.insert(stoi(num, 0, 2));
        }

        

        for (int number = 0; number <= n; number++) {

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


// ======================================= Approach - 2 ====================================

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans;

        for (int i = 0; i < n; i++) {
            char ch = nums[i][i];

            ans += (ch == '0') ? "1" : "0";
        }

        return ans;
    }
};



// Time Complexity ->O(n)
// Space Complexity -> O(1)

// ========================================================================================
