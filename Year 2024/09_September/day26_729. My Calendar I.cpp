// Problem Link -> https://leetcode.com/problems/my-calendar-i/description/

class MyCalendar {
public:
    set<pair<int, int>> calendar;

    MyCalendar() {
        // Constructor for initialization
    }
    
    bool book(int start, int end) {
        auto nextEvent = calendar.lower_bound({start, end});

        if (nextEvent != calendar.begin()) {
            auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;  
            }
        }

        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;  
        }

        calendar.insert({start, end});
        return true;
    }
};



// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
