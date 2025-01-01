// Problem Link -> https://leetcode.com/problems/minimum-cost-for-tickets/description/

class Solution {
public:
    int dp[366];

    int calculateMinCost(vector<int>& travelDays, vector<int>& ticketCosts, int& totalDays, int currentIndex) {
        if (currentIndex >= totalDays)
            return 0; // No more days to travel, no cost incurred

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        // Option 1: Use 1-day pass
        int costFor1Day = ticketCosts[0] + calculateMinCost(travelDays, ticketCosts, totalDays, currentIndex + 1);

        // Option 2: Use 7-day pass
        int nextIndexFor7Day = currentIndex;
        while (nextIndexFor7Day < totalDays && travelDays[nextIndexFor7Day] < travelDays[currentIndex] + 7) {
            nextIndexFor7Day++;
        }
        int costFor7Day = ticketCosts[1] + calculateMinCost(travelDays, ticketCosts, totalDays, nextIndexFor7Day);

        // Option 3: Use 30-day pass
        int nextIndexFor30Day = currentIndex;
        while (nextIndexFor30Day < totalDays && travelDays[nextIndexFor30Day] < travelDays[currentIndex] + 30) {
            nextIndexFor30Day++;
        }
        int costFor30Day = ticketCosts[2] + calculateMinCost(travelDays, ticketCosts, totalDays, nextIndexFor30Day);

        return dp[currentIndex] = min({costFor1Day, costFor7Day, costFor30Day});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int totalDays = days.size();
        return calculateMinCost(days, costs, totalDays, 0);
    }
};




// Tiem Complexity -> O(max_day)
// Space complexity -> O(n)
