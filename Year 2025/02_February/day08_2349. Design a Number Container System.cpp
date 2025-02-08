// Problem Link -> https://leetcode.com/problems/design-a-number-container-system/description/

// ======================================= Approach - 1 ====================================

class NumberContainers {
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)){
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index);

            if(numToIdx[prevNum].empty()){
                numToIdx.erase(prevNum);
            }
        }

        idxToNum[index] = number;
        numToIdx[number].insert(index);
    }
    
    int find(int number) {
        if(numToIdx.count(number)){
            return *numToIdx[number].begin();
        }

        return -1;
    }
};



//Time Complexity -> O(log(n))
//Space Complexity -> O(n)

// =========================================================================================


// ======================================= Approach - 2 ====================================

class NumberContainers {
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        idxToNum[index] = number;
        numToIdx[number].push(index);
    }
    
    int find(int number) {
        if(numToIdx.count(number)){
            auto& queueItem = numToIdx[number];

            while(!queueItem.empty()){
                int idx = queueItem.top();

                if(idxToNum[idx] == number) return idx;

                queueItem.pop();
            }
        }

        return -1;
    }
};

// =========================================================================================
