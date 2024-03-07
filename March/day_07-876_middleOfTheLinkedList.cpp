//----------------------------- BRUTE FORCE---------------------------------------------

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        temp = head;
        for(int i = 0; i < n/2; i++){
            temp = temp->next;
        }
        return temp;
    }
};

// Time Complexity -> O(n + n/2)
// Space Complexity -> O(1)

//--------------------------------------------------------------------------------------
