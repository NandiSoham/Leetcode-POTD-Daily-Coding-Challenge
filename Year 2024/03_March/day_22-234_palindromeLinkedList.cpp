// Problem Link -> https://leetcode.com/problems/palindrome-linked-list/

// ---------------------------------------- Approach -1 (Brute Force) --------------------------------

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};


// Time COmplexity -> O(2n)
// Space Complexity -> O(n)

//----------------------------------------------------------------------------------------------------

// ------------------------------------- Approach - 2 (Better Approach) ------------------------------

class Solution {
public:

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // Check if the linked list is empty or has only one node
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list starting from the middle
        ListNode* newHead = reverseLinkedList(slow->next);

        ListNode* left = head;
        ListNode* right = newHead;
        while(right != NULL){
            if(left->val != right->val){
                // Reverse the second half back to its original state
                reverseLinkedList(newHead); 
                return false;
            }
            left = left->next;
            right = right->next;
        }
        // Reverse the second half back to its original state
        reverseLinkedList(newHead);
        return true;
    }
};


// Time Complexity -> O(2n)
// Space Complexity -> O(1)

//----------------------------------------------------------------------------------------------------
