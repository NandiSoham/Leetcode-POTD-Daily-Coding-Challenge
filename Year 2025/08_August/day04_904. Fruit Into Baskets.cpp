// Problem Link -> https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int count = 0;
        unordered_map<int, int> fruitMap;

        while(right < n){
            fruitMap[fruits[right]]++;

            if(fruitMap.size() <= 2){
                count = max(count, right - left + 1);
            } else {
                fruitMap[fruits[left]]--;
                if(fruitMap[fruits[left]] == 0){
                    fruitMap.erase(fruits[left]);
                }
                left++;
            }

            right++;
        }

        return count;
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n)
