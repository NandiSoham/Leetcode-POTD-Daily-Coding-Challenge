// Problem Link -> https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleBookedIntervals;  
    vector<pair<int, int>> allBookings;  
    
    bool hasOverlap(int interval1Start, int interval1End, int interval2Start, int interval2End) {
        return max(interval1Start, interval2Start) < min(interval1End, interval2End);
    }
    
    pair<int, int> getOverlapRegion(int interval1Start, int interval1End, int interval2Start, int interval2End) {
        return {max(interval1Start, interval2Start), min(interval1End, interval2End)};
    }

    MyCalendarTwo() {
        // Constructor
    }
    
    bool book(int newStart, int newEnd) {
        for (pair<int, int> doubleBooking : doubleBookedIntervals) {
            if (hasOverlap(doubleBooking.first, doubleBooking.second, newStart, newEnd)) {
                return false; 
            }
        }

        for (pair<int, int> existingBooking : allBookings) {
            if (hasOverlap(existingBooking.first, existingBooking.second, newStart, newEnd)) {
                doubleBookedIntervals.push_back(getOverlapRegion(existingBooking.first, existingBooking.second, newStart, newEnd));
            }
        }

        allBookings.push_back({newStart, newEnd});
        return true;
    }
};



// Time Complexity -> O(n)
// Space Compelxity -> O()
