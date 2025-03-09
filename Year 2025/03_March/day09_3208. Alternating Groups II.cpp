// Problem Link -> https://leetcode.com/problems/alternating-groups-ii/description/

// ======================================= Approach - 1 (TLE) ====================================

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int groupCount = 0;

        for(int i = 0; i < k - 1; i++){
            colors.push_back(colors[i]);
        }

        for(int i = 0; i < n; i++){
            bool isAlternate = true;

            for(int j = i; j < i + k - 1; j++){
                if(colors[j] == colors[j + 1]){
                    isAlternate = false;
                    break;
                }
            }

            if(isAlternate) groupCount++;
        }

        return groupCount;
    }
};


// Time Complexity -> O(n * k)
// SPace Complexity -> O(1)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int N = n + (k - 1);
        int groupCount = 0;

        for(int i = 0; i < k - 1; i++){
            colors.push_back(colors[i]);
        }

        int startIdx = 0, endIdx = 1;
        while(endIdx < N){
            if(colors[endIdx] == colors[endIdx - 1]){
                startIdx = endIdx;
                endIdx++;
                continue;
            }

            if(endIdx - startIdx + 1 == k){
                groupCount++;
                startIdx++;
            }
            endIdx++;
        }

        return groupCount;
    }
};


// Time Complexity -> O(n + k)
// SPace Complexity -> O(1)

// =========================================================================================
