class TaskManager {
public:

    unordered_map<int,set<pair<int,int>>> userTaskPriority;
    unordered_map<int,int> taskUserId;
    unordered_map<int,int> taskPriority;
    set<pair<int,int>> st;

    TaskManager(vector<vector<int>>& tasks) {
        
        for(auto &x : tasks){

            int userId = x[0];
            int taskId = x[1];
            int priority = x[2];

            userTaskPriority[userId].insert({taskId,priority});
            taskUserId[taskId] = userId;
            taskPriority[taskId] = priority;
            st.insert({priority,taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        userTaskPriority[userId].insert({taskId,priority});
        taskUserId[taskId] = userId;
        taskPriority[taskId] = priority;
        st.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        
        int userId = taskUserId[taskId];
        int oldPriority = taskPriority[taskId];

        taskPriority[taskId] = newPriority;
        userTaskPriority[userId].erase({taskId,oldPriority});
        userTaskPriority[userId].insert({taskId,newPriority}); 
        st.erase({oldPriority,taskId});
        st.insert({newPriority,taskId});

    }
    
    void rmv(int taskId) {
        
        int userId = taskUserId[taskId];
        int priority = taskPriority[taskId];

        userTaskPriority[userId].erase({taskId,priority});
        taskUserId.erase(taskId);
        taskPriority.erase(taskId);
        st.erase({priority,taskId});
        
    }
    
    int execTop() {

        if(st.empty()) return -1;
        
        pair<int,int> p = *st.rbegin();
        st.erase({p.first,p.second});

        int userId = taskUserId[p.second];
        userTaskPriority[userId].erase({p.second,p.first});

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */