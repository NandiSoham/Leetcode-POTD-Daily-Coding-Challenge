// Problem Link -> https://leetcode.com/problems/maximum-average-pass-ratio/description/

class Solution {
public:
    #define Pair pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int totalClasses = classes.size();

        priority_queue<Pair> maxHeap;

        for (int classIndex = 0; classIndex < totalClasses; classIndex++) {
            double currentPassRatio = (double)classes[classIndex][0] / classes[classIndex][1];
            double newPassRatio = (double)(classes[classIndex][0] + 1) / (classes[classIndex][1] + 1);
            double improvement = newPassRatio - currentPassRatio;
            maxHeap.push({improvement, classIndex});
        }

        while (extraStudents--) {
            auto topElement = maxHeap.top();
            maxHeap.pop();

            double improvement = topElement.first;
            int classIndex = topElement.second;

            classes[classIndex][0]++;
            classes[classIndex][1]++;

            double currentPassRatio = (double)classes[classIndex][0] / classes[classIndex][1];
            double newPassRatio = (double)(classes[classIndex][0] + 1) / (classes[classIndex][1] + 1);
            improvement = newPassRatio - currentPassRatio;
            maxHeap.push({improvement, classIndex});
        }

        double totalAverageRatio = 0.0;
        for (int classIndex = 0; classIndex < totalClasses; classIndex++) {
            totalAverageRatio += (double)classes[classIndex][0] / classes[classIndex][1];
        }

        return totalAverageRatio / totalClasses;
    }
};

