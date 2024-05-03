// Problem Link -> https://leetcode.com/problems/compare-version-numbers/

// ---------------------------------------- Approach - 1  ---------------------------------------

class Solution {
public:

    vector<string> findRevisions(string versions){
        stringstream ss(versions);
        string revision = "";
        vector<string> revision_arr;

        while(getline(ss, revision,'.')){
            revision_arr.push_back(revision);
        }
        return revision_arr;
    }

    int compareVersion(string version1, string version2) {
        vector<string> first_version_tokens = findRevisions(version1);
        vector<string> second_version_tokens = findRevisions(version2);
        int n = first_version_tokens.size();
        int m = second_version_tokens.size();
        int i = 0;

        while(i < n || i < m){
            int num1 = i < n ? stoi(first_version_tokens[i]) : 0;
            int num2 = i < m ? stoi(second_version_tokens[i]) : 0;

            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            else i++;
        }
        return 0;
    }
};



// Time Complexity -> O(n+m)
// Space Complexity -> O(n+m)

//-----------------------------------------------------------------------------------------------
