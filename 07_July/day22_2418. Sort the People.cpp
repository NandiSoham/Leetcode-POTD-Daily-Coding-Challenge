// Problem Link -> https://leetcode.com/problems/sort-the-people/description/

// ------------------------------------- Approach - 1 --------------------------------

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        unordered_map<int, string> mp; 
        for(int i = 0; i < n; i++) {
            mp[heights[i]] = names[i];
        }

        sort(rbegin(heights), rend(heights));

        for(int i = 0; i < n; i++) {
            names[i] = mp[heights[i]];
        }

        return names;

    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

// -----------------------------------------------------------------------------------


// ------------------------------------- Approach - 2 --------------------------------

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int numPeople = names.size();
        vector<pair<string, int>> people(numPeople);

        for(int i = 0; i < numPeople; i++) {
            people[i] = make_pair(names[i], heights[i]);
        }

        auto compareHeights = [](auto &person1, auto &person2) {
            return person1.second > person2.second;
        };

        sort(begin(people), end(people), compareHeights);

        for(int i = 0; i < numPeople; i++) {
            names[i] = people[i].first;
        }

        return names;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)

// -----------------------------------------------------------------------------------

