// Problem Link -> https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevNode = dummy;
        ListNode* currNode = head;

        while(currNode){
            if(numSet.find(currNode->val) != numSet.end()){
                prevNode -> next = currNode -> next;
                delete currNode;
                currNode = prevNode -> next;
            } else {
                prevNode = prevNode -> next;
                currNode = currNode -> next;
            }
        }

        return dummy -> next;
    }
};



// Time Complexity -> O(m + n)
// Space Complexity -> O(n)
