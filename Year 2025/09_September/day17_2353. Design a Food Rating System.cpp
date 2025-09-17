// Problem Link -> https://leetcode.com/problems/design-a-food-rating-system/description/

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisineFoods;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string type = cuisines[i];
            int rate = ratings[i];

            cuisineFoods[type].insert({-rate, food});
            foodToCuisine[food] = type;
            foodToRating[food] = rate;
        }
    }
    
    void changeRating(string food, int newRate) {
        string type = foodToCuisine[food];
        int oldRate = foodToRating[food];

        cuisineFoods[type].erase({-oldRate, food});
        cuisineFoods[type].insert({-newRate, food});
        foodToRating[food] = newRate;
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};


// Time Complexity -> O(n log(n))
// Space Complexity -> O(n)
