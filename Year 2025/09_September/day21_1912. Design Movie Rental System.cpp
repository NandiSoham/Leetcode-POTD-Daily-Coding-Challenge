// Problem Link -> https://leetcode.com/problems/design-movie-rental-system/description/

class MovieRentingSystem {
public:
    set<vector<int>> rentedMovies;
    unordered_map<int, set<vector<int>>> availableMovies;
    unordered_map<int, unordered_map<int,int>> moviePrice;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], cost = e[2];
            availableMovies[movie].insert({cost, shop});
            moviePrice[movie][shop] = cost;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if (availableMovies.count(movie)) {
            for (auto &entry : availableMovies[movie]) {
                result.push_back(entry[1]);
                if (result.size() == 5) break;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int cost = moviePrice[movie][shop];
        availableMovies[movie].erase({cost, shop});
        rentedMovies.insert({cost, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int cost = moviePrice[movie][shop];
        rentedMovies.erase({cost, shop, movie});
        availableMovies[movie].insert({cost, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (auto &entry : rentedMovies) {
            result.push_back({entry[1], entry[2]}); 
            if (result.size() == 5) break;
        }
        return result;
    }
};
