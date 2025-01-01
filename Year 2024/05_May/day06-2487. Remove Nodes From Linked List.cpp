// Problem Link -> https://leetcode.com/problems/remove-nodes-from-linked-list/description/

// ---------------------------------------- Approach - 1 (Using Stack) ---------------------------------------

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> nodeStack;
        ListNode* currNode = head;

        while(currNode!= NULL){
            nodeStack.push(currNode);
            currNode = currNode->next;
        }

        currNode = nodeStack.top();
        nodeStack.pop();

        int maxValueNode = currNode->val;
        ListNode* ansHead = new ListNode(currNode->val);

        while(!nodeStack.empty()){
            currNode = nodeStack.top();
            nodeStack.pop();

            if(currNode->val < maxValueNode) continue;
            else{
                ListNode* newAnsHead = new ListNode(currNode->val);
                newAnsHead->next = ansHead;
                ansHead = newAnsHead;
                maxValueNode = currNode->val;
            }
        }
        return ansHead;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(n)

//-----------------------------------------------------------------------------------------------

// ---------------------------------------- Approach - 2 (Using Recursion) ---------------------------------------

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* nextNode = removeNodes(head->next);
        if(head->val < nextNode->val){
            delete head;
            return nextNode;
        } else {
            head->next = nextNode;
            return head;
        }

    }
};


// Time Complexity -> O(n)
// Space Complexity -> O(n) auxilary space for recursion

//-----------------------------------------------------------------------------------------------
