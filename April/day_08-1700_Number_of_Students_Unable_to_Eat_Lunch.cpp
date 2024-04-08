class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int arr[2] = {0};   // arr[0] -> count of students who like circular ( 0 wala) sandwiches
                            // arr[1] -> count of students who like square ( 1 wala) sandwiches
        
        for(int &st : students){
            arr[st]++;
        }

        for(int i = 0; i < n; i++){
            if(arr[sandwiches[i]] == 0) return n - i;
            arr[sandwiches[i]]--;
        }
        return 0;
    }
};



// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Problem Link -> https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
