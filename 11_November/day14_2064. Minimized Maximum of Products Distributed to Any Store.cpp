// Problem Link -> https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto can_distribute = [&](int x) {
            int stores = 0;
            for (int q : quantities) {
                stores += ceil((double)q / x);
            }
            return stores <= n;
        };

        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        int res = 0;

        while (l <= r) {
            int x = l + (r - l) / 2;
            if (can_distribute(x)) {
                res = x;
                r = x - 1;
            } else {
                l = x + 1;
            }
        }
        return res;
    }
};
