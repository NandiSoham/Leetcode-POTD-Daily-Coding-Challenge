class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> mpp;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        mpp[0] = dummyNode;

        while(head != NULL){
            prefixSum += head -> val;

            if(mpp.find(prefixSum) != mpp.end()){
                ListNode* start = mpp[prefixSum];
                ListNode* temp = start;
                int curPreSum = prefixSum;

                while(temp != head){
                    temp = temp->ne xt;
                    curPreSum += temp->val;

                    if(temp != head){
                        mpp.erase(curPreSum);
                    }
                }
                start->next = head->next;
            } else {
                mpp[prefixSum] = head;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};



// Time Complexity -> O(n^2)
// Space Complexity -> O(n)
// Problem Link -> https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
