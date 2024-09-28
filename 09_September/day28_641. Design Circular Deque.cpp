// Problem Link -> https://leetcode.com/problems/design-circular-deque/description/

class MyCircularDeque {
public:
    vector<int> dequeData;  
    int maxCapacity;       
    int frontIndex;         
    int rearIndex;         
    int currentSize;        

    MyCircularDeque(int k) {
        maxCapacity = k;
        dequeData = vector<int>(maxCapacity, 0);
        frontIndex = 0;
        rearIndex  = maxCapacity - 1;
        currentSize = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        frontIndex = (frontIndex - 1 + maxCapacity) % maxCapacity;
        dequeData[frontIndex] = value;
        currentSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        rearIndex = (rearIndex + 1) % maxCapacity;
        dequeData[rearIndex] = value;
        currentSize++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        frontIndex = (frontIndex + 1) % maxCapacity;
        currentSize--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        rearIndex = (rearIndex - 1 + maxCapacity) % maxCapacity;
        currentSize--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }        

        return dequeData[frontIndex];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return dequeData[rearIndex];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == maxCapacity;
    }
};




// Time Complexity -> O(1)
// Space Complexity -> O(k)
