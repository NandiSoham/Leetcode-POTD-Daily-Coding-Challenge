class Solution {
public:

    void findNeighbours(unordered_set<string>& isVisited, queue<string>& q, string& curState){
        for(int i = 0; i < 4; i++){
            char curChar = curState[i] ;
            char antiClockWiseRotate = curChar == '0' ? '9' : curChar - 1;
            char clockWiseRotate = curChar == '9' ? '0' : curChar + 1;

            curState[i] = antiClockWiseRotate;
            if(isVisited.find(curState) == isVisited.end()){
                q.push(curState);
                isVisited.insert(curState);
            }

            curState[i] = clockWiseRotate;
            if(isVisited.find(curState) == isVisited.end()){
                q.push(curState);
                isVisited.insert(curState);
            }
            curState[i] = curChar;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> isVisited(deadends.begin(), deadends.end());
        string startState = "0000";
        queue<string> q;
        q.push(startState);
        int curLevel = 0;

        if(isVisited.find(startState) != isVisited.end()) return -1;

        while(!q.empty()){
            int queSize = q.size();
            while(queSize--){
                string curState = q.front();
                q.pop();
                if(curState == target) return curLevel;

                findNeighbours(isVisited, q, curState);
            }
            curLevel++;
        }
        return -1;
    }
};



// Time Complexity -> O(n X w) where n is numbers in each wheel and w is number of total wheels
// Space Complexity -> O(n X w) where n is numbers in each wheel and w is number of total wheels
// Problem Link -> https://leetcode.com/problems/open-the-lock/description/
