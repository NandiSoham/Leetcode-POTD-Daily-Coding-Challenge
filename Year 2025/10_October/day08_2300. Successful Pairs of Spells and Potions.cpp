// Problem lInk -> https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

class Solution {
public:
    int findFirstValidPotion(int left, int right, vector<int>& potions, int target) {
        int position = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (potions[mid] >= target) {
                position = mid;       
                right = mid - 1;     
            } else {
                left = mid + 1;      
            }
        }

        return position;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        int m = potions.back();

        vector<int> result;

        for (int spell : spells) {
            long long requiredPotion = ceil((1.0 * success) / spell);

            if (requiredPotion > m) {
                result.push_back(0);
                continue;
            }

            int idx = findFirstValidPotion(0, n - 1, potions, requiredPotion);
            result.push_back(n - idx);
        }

        return result;
    }
};


// Time Complexity -> O(n log n + m log n)
// Space complexity -> O(1)
