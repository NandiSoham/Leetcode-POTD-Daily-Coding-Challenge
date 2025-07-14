// Problem Link -> https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

// ========================== Approach - 1 ========================

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    int getDecimalValue(ListNode* head) {
        head= reverseLL(head);

        int result = 0;
        int power = 0;
        while(head) {
            if(head->val == 1) {
                result += pow(2, power);
            }
            power++;
            head = head->next;
        }

        return result;
    }
};


// Time Complexity -> O(n)
// Space complexity -> O(1)

// ==========================================================================

// ========================== Approach - 2 ========================

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while(head) {
            result = (result << 1) | (head->val);

            head = head->next;
        }        
        return result;
    }
};


// Time Complexity -> O(n)
// Space complexity -> O(1)

// ==========================================================================


