// Problem Link -> https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

// ------------------------------------ Approach - 1 ----------------------------------

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* currNode = head;
        ListNode* nextNode = head -> next;

        while(nextNode != NULL){
            ListNode* gcdNode = new ListNode(__gcd(currNode -> val, nextNode -> val));
            currNode -> next = gcdNode;
            gcdNode -> next = nextNode;

            currNode = nextNode;
            nextNode = nextNode -> next;
        }

        return head;
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O(1)

// ------------------------------------------------------------------------------------


// ------------------------------------ Approach - 2 ----------------------------------

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* tempNode = insertGreatestCommonDivisors(head -> next);
        ListNode* gcdNode = new ListNode(__gcd(head -> val, head -> next -> val));

        gcdNode -> next = tempNode;
        head -> next = gcdNode;

        return head;
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O(1)

// ------------------------------------------------------------------------------------
