// Problem Link -> https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/

class Solution {
public:
    using ll = long long;

    ll flowerGame(int n, int m) {
        ll oddN  = (n + 1) / 2;
        ll evenN = n / 2;
        ll oddM  = (m + 1) / 2;
        ll evenM = m / 2;

        return oddN * evenM + evenN * oddM;
    }
};



// Time Complexity -> O(1)
// Space Complexity -> O(1)
