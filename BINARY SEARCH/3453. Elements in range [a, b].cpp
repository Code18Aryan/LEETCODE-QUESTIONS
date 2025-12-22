class Solution {
  public:
  
    int findLowerBound(vector<int>&nums, int target, int n){
        
        int index = n;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] >= target){
                
                index = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return index;
    }
    
    int findUpperBound(vector<int>&nums, int target, int n){
        
        int index = n;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] > target){
                
                index = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return index;
    }
  
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> ans;
        
        for(auto &x : queries){
            
            int a = x[0];
            int b = x[1];
            
            // int first = lower_bound(arr.begin(),arr.end(),a) - arr.begin();
            // int last = upper_bound(arr.begin(),arr.end(),b) - arr.begin();
            
            int first = findLowerBound(arr,a,n);
            int last = findUpperBound(arr,b,n);
            
            ans.push_back(last - first);
        }
        
        return ans;
    }
};