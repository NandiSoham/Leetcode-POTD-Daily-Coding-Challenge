class Solution {
    int n;
    vector<vector<int>> dp;

public:
    int child1Collect(vector<vector<int>>& fruits) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
            dp[i][i] = 0;
        }
        return ans;
    }

    int child2Collect(int i, int j, vector<vector<int>>& fruits) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        
        if (i == j || i > j) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int leftcorner = fruits[i][j] + child2Collect(i + 1, j - 1, fruits);
        int middle = fruits[i][j] + child2Collect(i + 1, j, fruits);
        int rightcorner = fruits[i][j] + child2Collect(i + 1, j + 1, fruits);

        return dp[i][j] = max({middle, rightcorner, leftcorner});
    }

    int child3Collect(int i, int j, vector<vector<int>>& fruits) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        if (i == j || j > i) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int topcorner   = fruits[i][j] + child3Collect(i - 1, j + 1, fruits);
        int right       = fruits[i][j] + child3Collect(i, j + 1, fruits);
        int rightcorner = fruits[i][j] + child3Collect(i + 1, j + 1, fruits);

        return dp[i][j] = max({right, rightcorner, topcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp.resize(n, vector<int>(n, -1));

        int firstChildScore = child1Collect(fruits);

        int secondChildScore = child2Collect(0, n - 1, fruits);

        int thirdChildScore  = child3Collect(n - 1, 0, fruits);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }    
};
