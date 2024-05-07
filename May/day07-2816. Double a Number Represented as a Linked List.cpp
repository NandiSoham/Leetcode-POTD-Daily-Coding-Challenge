// Problem Link -> https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5){
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }

        ListNode* currNode = head;
        while(currNode != NULL){
            currNode->val = (currNode->val * 2) % 10;

            if(currNode->next != NULL && currNode->next->val >= 5){
                currNode->val += 1;
            }
            currNode = currNode->next;
        }
        return head;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)


// ---------------------------------------- Approach - 2 (Using Recursion) ---------------------------------------

class Solution {
public:

    int handleCarry(ListNode* head){
        if(head == 0) return 0;

        int carry = handleCarry(head->next);
        int newVal = (head->val * 2) + carry;
        head->val = newVal % 10;

        return (newVal) >= 10 ? 1: 0;
    }

    ListNode* doubleIt(ListNode* head) {
        int lastCarry = handleCarry(head);

        if(lastCarry > 0){
            ListNode* newHead = new ListNode(lastCarry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n) auxilary space for recursion

//-----------------------------------------------------------------------------------------------
