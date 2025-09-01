// Problem Link -> https://leetcode.com/problems/maximum-average-pass-ratio/description/

class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> maxHeap; 

        for(int i = 0; i < n; i++) {

            double currRatio = (double)classes[i][0] / classes[i][1];
            double nextRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double improvement = nextRatio - currRatio;
            maxHeap.push({improvement, i});
        }
        
        while(extraStudents--) {
            
            auto topClass = maxHeap.top();
            maxHeap.pop();

            double gain = topClass.first;
            int classIdx = topClass.second;

            classes[classIdx][0]++; 
            classes[classIdx][1]++; 

            double currRatio = (double)classes[classIdx][0] / classes[classIdx][1];
            double nextRatio = (double)(classes[classIdx][0] + 1) / (classes[classIdx][1] + 1);
            gain = nextRatio - currRatio;

            maxHeap.push({gain, classIdx});
        }

        double sumRatios = 0.0;
        for(int i = 0; i < n; i++) {
            sumRatios += (double)classes[i][0] / classes[i][1];
        }

        return sumRatios / n;
    }
};


// Time Complexity -> O(extraStudents * log n)
// Space Complexity -> O(n)
