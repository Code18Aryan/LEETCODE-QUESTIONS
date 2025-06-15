class Solution {
  public:
  
    
    int solve(vector<int>&nums, int mid){
        
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            sum += ceil((double)nums[i]/(double)mid);
        }
        
        return sum;
    }
  
  
    int smallestDivisor(vector<int>& arr, int k) {
       
        int low = 1;
        int high = 1e6;
        int ans  = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            int sum = solve(arr,mid);
            
            if(sum <= k){
                
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return ans;
    }
};
