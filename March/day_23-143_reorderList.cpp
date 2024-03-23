class Solution {
public:

    ListNode* revLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* last = revLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }   

    void reorderList(ListNode* head) {        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = revLinkedList(slow);
        ListNode* curr = head;

        while(rev->next != NULL){
            ListNode* currtemp = curr->next;
            curr->next = rev;

            ListNode* rev_temp = rev->next;
            rev->next = currtemp;

            curr = currtemp;
            rev = rev_temp;
        }
    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(1)
