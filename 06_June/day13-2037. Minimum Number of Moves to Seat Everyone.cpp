// Problem Link -> https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int result = 0;
        for(int i = 0; i < seats.size(); i++){
            result += abs(seats[i] - students[i]);
        }

        return result;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)
