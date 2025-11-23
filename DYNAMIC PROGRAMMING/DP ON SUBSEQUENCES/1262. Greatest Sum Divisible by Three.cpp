class Solution {
public:

    int solve(int index, int n,int sum, vector<int>&nums, vector<vector<int>>&dp){

        if(index >= n){

            if(sum == 0) return 0;
            
            return INT_MIN/2;
        }

        if(dp[index][sum] != -1){

            return dp[index][sum];
        }
        // int take = 0;

        int take = nums[index] + solve(index +1, n, (sum + nums[index]) % 3, nums,dp);
        int notTake = solve(index+1,n,sum,nums,dp);

        return dp[index][sum] = max(take,notTake);
    }

    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(3,-1));
        return solve(0,n,0,nums,dp);

    }
};