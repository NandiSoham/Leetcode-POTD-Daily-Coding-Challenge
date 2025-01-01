// Problem Link -> https://leetcode.com/problems/split-linked-list-in-parts/description/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalNodes = 0;
        ListNode* currNode = head;

        while(currNode != NULL){
            totalNodes++;
            currNode = currNode->next;
        }

        currNode = head;
        ListNode* prevNode = NULL;
        vector<ListNode*> result(k, NULL);
        int nodePerPart = totalNodes / k;
        int extraNodes = totalNodes % k;

        for(int i = 0; i < k && currNode != NULL; i++){
            result[i] = currNode;

            for(int count = 1; count <= nodePerPart + (extraNodes > 0 ? 1 : 0); count++){
                prevNode = currNode;
                currNode = currNode -> next;
            }

            prevNode -> next = NULL;
            extraNodes--;
        }

        return result;
    }
};



// Time Complexity -> O(k + totalNodes)
// Space Complexity -> O(1)
