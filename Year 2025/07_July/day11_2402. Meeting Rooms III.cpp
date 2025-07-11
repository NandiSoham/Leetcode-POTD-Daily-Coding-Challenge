// Problem Link -> https://leetcode.com/problems/meeting-rooms-iii/description/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());

        vector<int> roomUsageCount(n, 0);
        vector<long long> roomNextFreeTime(n, 0);

        for(vector<int> &it : meetings){
            int startTime = it[0];
            int endTime = it[1];
            int duration = endTime - startTime;
            bool roomAssigned = false;
            long long earliestFreeTime = LLONG_MAX;
            int earliestRoomIdx = 0;

            // assign to available room
            for(int room = 0; room < n; room++){
                if(roomNextFreeTime[room] <= startTime){
                    roomAssigned = true;
                    roomNextFreeTime[room] = endTime;
                    roomUsageCount[room]++;
                    break;
                }

                // track earlisest available room
                if (roomNextFreeTime[room] < earliestFreeTime) {
                    earliestFreeTime = roomNextFreeTime[room];
                    earliestRoomIdx = room;
                }
                
            }

            // no room was free, so delay and assign to the earliest available room
            if (!roomAssigned) {
                roomNextFreeTime[earliestRoomIdx] += duration;
                roomUsageCount[earliestRoomIdx]++;
            }
        }

        int mostUsedRoom = -1;
        int maxUsage = 0;

        // find the room with maximum usage
        for (int room = 0; room < n; room++) {
            if (roomUsageCount[room] > maxUsage) {
                maxUsage = roomUsageCount[room];
                mostUsedRoom = room;
            }
        }

        return mostUsedRoom;
    }
};
