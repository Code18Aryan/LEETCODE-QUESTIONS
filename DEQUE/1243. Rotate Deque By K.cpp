class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        
       int n = dq.size();
       
       k = k % n;
       
       if(k == 0) return;
       
       if(type == 1){
           
           while(k--){
               
               dq.push_front(dq.back());
               dq.pop_back();
           }
       }
       
       else if(type == 2){
           
           while(k--){
               
               dq.push_back(dq.front());
               dq.pop_front();
           }
       }
        
    }
};