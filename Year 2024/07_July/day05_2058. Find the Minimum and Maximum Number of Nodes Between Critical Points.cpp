// Problem Link -> https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentPosition = 1;
        int firstCriticalPosition = 0;
        int previousCriticalPosition = 0;
        int minimumDistance = INT_MAX;

        while (currentNode->next) {
            if ((currentNode->val < previousNode->val &&
                 currentNode->val < currentNode->next->val) ||
                (currentNode->val > previousNode->val &&
                 currentNode->val > currentNode->next->val)) {

                if (previousCriticalPosition == 0) {
                    previousCriticalPosition = currentPosition;
                    firstCriticalPosition = currentPosition;
                } else { 
                    minimumDistance =
                        min(minimumDistance,
                            currentPosition - previousCriticalPosition);
                    previousCriticalPosition = currentPosition;
                }
            }
            currentPosition++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        int maximumDistance = previousCriticalPosition - firstCriticalPosition;
        if (minimumDistance == INT_MAX)
            return {-1, -1};

        return {minimumDistance, maximumDistance};
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
