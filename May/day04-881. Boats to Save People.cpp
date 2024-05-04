class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int light_weight_person = 0;
        int heavy_weight_person = people.size() - 1;
        int boat_count = 0;

        while(light_weight_person <= heavy_weight_person){
            if(people[light_weight_person] + people[heavy_weight_person] <= limit){
                light_weight_person++;
                heavy_weight_person--;
            } else {
                heavy_weight_person--;
            }
            boat_count++;
        }
        return boat_count;
    }

};


// Time COmplexity -> O(n)
// Space Complexity -> O(1)
// Probelm Link -> https://leetcode.com/problems/boats-to-save-people/description/
