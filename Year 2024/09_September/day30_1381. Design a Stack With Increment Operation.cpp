// Problem Link -> https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

class CustomStack {
public:
    vector<int> stackElements;  
    vector<int> incrementValues; 
    int maxCapacity; 

    CustomStack(int maxSize) {
        maxCapacity = maxSize;
    }
    
    void push(int value) {
        if (stackElements.size() < maxCapacity) {
            stackElements.push_back(value);
            incrementValues.push_back(0); 
        }
    }
    
    int pop() {
        if (stackElements.empty()) {
            return -1;
        }

        int topIndex = stackElements.size() - 1;

        if (topIndex > 0) {
            incrementValues[topIndex - 1] += incrementValues[topIndex]; 
        }

        int topValue = stackElements[topIndex] + incrementValues[topIndex]; 
        stackElements.pop_back();
        incrementValues.pop_back();
        
        return topValue;
    }
    
    void increment(int count, int value) {
        int index = min(count, (int)stackElements.size()) - 1;
        if (index >= 0) {
            incrementValues[index] += value; 
        }
    }
};
