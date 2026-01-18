class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
       
       unordered_map<int,int> mpp;
     
       for(auto x : arr) mpp[x]++;
       
       stack<int> stk;
       vector<int> ans(arr.size());
       int index = arr.size()-1;
       
       for(int i=arr.size()-1; i>=0; i--){
           
           if(stk.empty()) ans[index--] = -1;
              
           else if(!stk.empty() && mpp[stk.top()] > mpp[arr[i]]){
               
               ans[index--] = stk.top();
              
           }
           
           else if(!stk.empty() && mpp[stk.top()] <= mpp[arr[i]]){
               
               while(!stk.empty() && mpp[stk.top()] <= mpp[arr[i]]){
                   
                   stk.pop();
               }
               
               if(stk.empty()){
                   
                   ans[index--] = -1;
               }
               
               else{
                   
                   ans[index--] = stk.top();
               }
           }
           
           
           stk.push(arr[i]);
       }
       
       return ans;
    }
};
