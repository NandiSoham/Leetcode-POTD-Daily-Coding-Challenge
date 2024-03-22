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
