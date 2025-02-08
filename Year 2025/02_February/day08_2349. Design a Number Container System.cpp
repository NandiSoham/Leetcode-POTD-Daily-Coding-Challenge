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
