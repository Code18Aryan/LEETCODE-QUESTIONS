class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        
        // 1st Approach using stack
        
        /*
        
        stack<int> st;
        
        while(!q.empty()){
            
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            
            q.push(st.top());
            st.pop();
        }  */
        
        // 2nd Approach using recursion
        
        if(q.empty()) return;
        
        int element = q.front();
        q.pop();
        
        reverseQueue(q);
        
        q.push(element);
    
        
    }
};