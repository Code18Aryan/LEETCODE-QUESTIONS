class Solution {
  public:
    
    typedef pair<int,int> p;
  
    int minCandy(vector<int> &arr) {
       
       vector<p> priority(arr.size(),{1,1});
       
       int toatalCandy = 0;
       
       for(int i=1; i<arr.size(); i++){
           
           if(arr[i] > arr[i-1]){
               
               priority[i].first = priority[i].first + priority[i-1].first;
           }
       }
       
       for(int i=arr.size()-2; i>=0; i--){
           
           if(arr[i] > arr[i+1]){
               
               priority[i].second = priority[i].second + priority[i+1].second;
           }
       }
       
       for(auto &x : priority){
           
           toatalCandy += max(x.first,x.second);
       }
       
       return toatalCandy;
        
    }
};
