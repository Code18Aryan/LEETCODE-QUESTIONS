class Solution {
public:

    // This problem is based on 0/1 knapsack where for a given instance,I can pick or notpick

    int findMax(int index, vector<int>&nums, vector<int> &dp){

        if(index == 0) return nums[0];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

       int robbed = nums[index] + findMax(index -2, nums,dp);
       int notRobbed = findMax(index -1, nums,dp);

       return dp[index] =  max(robbed, notRobbed);
    }

    int nonAdjacent(vector<int>& nums) {

        int n = nums.size();

        // vector<int>  dp(n+1,-1);
        // return findMax(n-1,nums,dp);

        // BOTTOM - UP APPROACH
        // BASE CASE DP[0] = 0; dp[1] = nums[0];


        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){

            int take = nums[i-1] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take,notTake);
        }

        return dp[n];
        
    }

};
