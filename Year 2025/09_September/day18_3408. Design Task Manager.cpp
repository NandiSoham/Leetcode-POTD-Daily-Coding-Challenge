// Problem Link -> https://leetcode.com/problems/design-task-manager/description/

class TaskManager {
public:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPrio;
    set<pair<int,int>> taskSet;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            int userId = it[0];
            int taskId = it[1];
            int prio = it[2];

            taskSet.insert({prio, taskId});
            taskToUser[taskId] = userId;
            taskToPrio[taskId] = prio;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskSet.insert({priority, taskId});
        taskToUser[taskId] = userId;
        taskToPrio[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskToPrio[taskId];
        taskSet.erase({oldPriority, taskId});
        taskSet.insert({newPriority, taskId});
        taskToPrio[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int oldPriority = taskToPrio[taskId];
        taskSet.erase({oldPriority, taskId});
        taskToPrio.erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if(taskSet.size() == 0) return -1;

        int taskId = taskSet.rbegin()->second;
        int userId = taskToUser[taskId];
        rmv(taskId);
        return userId;
    }
};




// Time Complexity -> O(n log(n))
// Space Complexity -> O(n)
