// Problem Link -> https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        vector<int> discountedPrices(begin(prices), end(prices));
        stack<int> indexStack;
        
        for (int currentIndex = 0; currentIndex < size; currentIndex++) {
            while (!indexStack.empty() && prices[currentIndex] <= prices[indexStack.top()]) {
                discountedPrices[indexStack.top()] -= prices[currentIndex];
                indexStack.pop();
            }
            indexStack.push(currentIndex);
        }

        return discountedPrices;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)
