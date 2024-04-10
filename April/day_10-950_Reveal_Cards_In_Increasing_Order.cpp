class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n,0);
        bool isSkip = false;
        int i = 0;  // to traverse in deck
        int j = 0;  // to traverse in ans

        sort(deck.begin(), deck.end());
        while(i < n){
            if(ans[j] == 0){
                if(isSkip == false){
                    ans[j] = deck[i];
                    i++;
                }
                isSkip = !isSkip;
            }
            j = (j + 1) % n;
        }
        return ans;
    }
};



// Time Complexity -> O(n logn)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/reveal-cards-in-increasing-order/
