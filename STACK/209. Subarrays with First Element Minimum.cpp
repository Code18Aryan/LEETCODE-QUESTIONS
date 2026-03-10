class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            
            if(st.empty()){
                
                st.push(i);
            }
            
            else{
                
                if(!st.empty() && arr[i] < arr[st.top()]){
                    
                    while(!st.empty() && arr[i] < arr[st.top()]){
                        
                        cnt += (i - st.top());
                        st.pop();
                    }
                    
                }
                
                st.push(i);
            }
            
            
        }
        
        while(!st.empty()){
            
            cnt += (n-st.top());
            st.pop();
        }
        
        return cnt;
    }
};