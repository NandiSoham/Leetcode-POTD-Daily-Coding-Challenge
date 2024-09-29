// Problem Link -> https://leetcode.com/problems/all-oone-data-structure/description/

class AllOne {
private:
    struct DListNode {
        int count;
        list<string> keysList;  
        DListNode *prev, *next;
        DListNode(int cnt) : count(cnt), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<string, DListNode*> keyToNodeMap;

    DListNode *listHead, *listTail;

    DListNode* addNodeAfter(DListNode *previousNode, int count) {
        DListNode *newNode = new DListNode(count);
        newNode->next = previousNode->next;
        newNode->prev = previousNode;
        if (previousNode->next) {
            previousNode->next->prev = newNode;
        }
        previousNode->next = newNode;
        if (listTail == previousNode) {
            listTail = newNode;
        }
        return newNode;
    }

    void removeNode(DListNode *node) {
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (listTail == node) {
            listTail = node->prev;
        }
        delete node;
    }

public:
    AllOne() {
        listHead = new DListNode(0);
        listTail = listHead;
    }

    void inc(string key) {
        if (keyToNodeMap.find(key) == keyToNodeMap.end()) {
            if (listHead->next == nullptr || listHead->next->count != 1) {
                addNodeAfter(listHead, 1);
            }
            listHead->next->keysList.push_front(key);
            keyToNodeMap[key] = listHead->next;
        } else {
            DListNode *currentNode = keyToNodeMap[key];
            int currentCount = currentNode->count;
            if (currentNode->next == nullptr || currentNode->next->count != currentCount + 1) {
                addNodeAfter(currentNode, currentCount + 1);
            }
            currentNode->next->keysList.push_front(key);
            keyToNodeMap[key] = currentNode->next;
            currentNode->keysList.remove(key);
            if (currentNode->keysList.empty()) {
                removeNode(currentNode);
            }
        }
    }

    void dec(string key) {
        DListNode *currentNode = keyToNodeMap[key];
        int currentCount = currentNode->count;
        
        currentNode->keysList.remove(key);
        if (currentCount == 1) {
            keyToNodeMap.erase(key);
        } else {
            if (currentNode->prev == listHead || currentNode->prev->count != currentCount - 1) {
                addNodeAfter(currentNode->prev, currentCount - 1);
            }
            currentNode->prev->keysList.push_front(key);
            keyToNodeMap[key] = currentNode->prev;
        }
        
        if (currentNode->keysList.empty()) {
            removeNode(currentNode);
        }
    }

    string getMaxKey() {
        return (listTail == listHead) ? "" : listTail->keysList.front();
    }

    string getMinKey() {
        return (listHead->next == nullptr) ? "" : listHead->next->keysList.front();
    }
};



// Time Complexity -> O(1)
// Space Complexity -> O(n)
