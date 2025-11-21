class Solution {
  public:
    // using binary search

    int findElement(vector<int>&nums, int element){
        
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low +(high-low)/2;
            
            if(nums[mid] <= element){
                
                ans = mid;
                low = mid+1;
            }
            
            else high = mid-1;
        }
        
            return ans == -1 ? high : ans;
    }
  
  
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
       
       int n = a.size();
       int m = b.size();
      
      // if(m > n) return countLessEq(b,a);
       
       sort(b.begin(),b.end());
       
       vector<int> ans(n);
       
       for(int i=0; i<n; i++){
           
           int index = findElement(b,a[i]);
           
            ans[i] = index + 1;
       }
       
       return ans;
       
       
       
       
        
    }
};
