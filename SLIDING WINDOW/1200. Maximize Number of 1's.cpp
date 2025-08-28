class Solution {
  public:
    int maxOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = 0;
        int i = 0, j = 0;
        int countZero = 0;
        
        
        while(j < n){
            
            if(nums[j] == 0){
                
                countZero++;
            }
            
            while(countZero > k){
                
                if(nums[i] == 0){
                    
                    countZero--;
                }
                
                i++;
            }
            
            maxi = max(maxi, j-i+1);
            j++;
        }
        
        return maxi;
    }
};
