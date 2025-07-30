class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
       
       int sum = 0;
       unordered_map<int,int> mpp;
       int cnt = 0;
       mpp[0] = 1;
       
       for(int i=0; i<arr.size(); i++){
           
           sum += arr[i];
           
           if(mpp.find(sum-k) != mpp.end()){
               
               cnt += mpp[sum-k];
           }
           
           mpp[sum]++;
       }
       
       return cnt;
        
    }
};