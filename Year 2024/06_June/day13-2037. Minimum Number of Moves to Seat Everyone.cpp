// Problem Link -> https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

// ------------------------------------- Approach - 1 --------------------------------------- 

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

// ------------------------------------------------------------------------------------------

// ------------------------------------- Approach - 2 --------------------------------------- 

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        vector<int> seat_position(101, 0);
        vector<int> student_position(101, 0);

        for (auto& it : seats) {
            seat_position[it]++;
        }

        for (auto& it : students) {
            student_position[it]++;
        }

        int seat_ptr = 0, stud_ptr = 0;
        int move_count = 0;
        while (seat_ptr <= 100 && stud_ptr <= 100) {
            if (seat_position[seat_ptr] == 0)
                seat_ptr++;
            if (student_position[stud_ptr] == 0)
                stud_ptr++;

            if (seat_ptr <= 100 && stud_ptr <= 100 &&
                seat_position[seat_ptr] != 0 &&
                student_position[stud_ptr] != 0) {
                move_count += abs(seat_ptr - stud_ptr);
                seat_position[seat_ptr]--;
                student_position[stud_ptr]--;
            }
        }

        return move_count;
    }
};


// ------------------------------------------------------------------------------------------
