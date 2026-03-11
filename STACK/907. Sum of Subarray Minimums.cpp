class Solution {
public:

    vector<int> findNSR(vector<int>&nums, int n){
        
        stack<pair<int,int>> stk;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
        
        
            while(!stk.empty() && stk.top().first > nums[i]){
                
                stk.pop();
                
            }
                
            ans[i] = stk.empty() ? n : stk.top().second;
            
            stk.push({nums[i],i});
        }
        
        return ans;
    } 
    
    vector<int> findNSL(vector<int>&nums, int n){
        
        stack<pair<int,int>> stk;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
           
            while(!stk.empty() && stk.top().first >= nums[i]){
                
                stk.pop();
                
            }
                
            ans[i] = stk.empty() ? -1 : stk.top().second;
            
            
            stk.push({nums[i],i});
        }
        
        return ans;
    }
  
  

    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<int> nsl = findNSL(nums, n);
        vector<int> nsr = findNSR(nums, n);
        long long sum = 0;
        
        for(int i=0; i<n; i++){
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            long long contrib = (nums[i] * left % mod) * right % mod;
            sum = (sum + contrib) % mod;
        }
        
        return (int)sum;
    }
};