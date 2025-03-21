// Problem Link -> https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adjGraph; 
        unordered_map<string, int> indegree;
        unordered_set<string> recipeSet(recipes.begin(), recipes.end());

        // Building the adjGraph and in-degree mapping
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                adjGraph[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;
        vector<string> ans;

        // Initializing queue with supplies
        for (const string& supply : supplies) {
            q.push(supply);
        }

        while (!q.empty()) {
            string supply = q.front();
            q.pop();

            if (recipeSet.count(supply)) {
                ans.push_back(supply);
            }

            for (const string& recipe : adjGraph[supply]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};


// Time Complexity -> O(V + E)
// Space Complexity -> O(V + E)
