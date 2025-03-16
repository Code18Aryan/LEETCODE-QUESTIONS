LINK - https://leetcode.com/problems/jump-game-ii/

class Solution {
public:

    int findMinJump(int index, int n,  vector<int>&nums, vector<int>&dp){

        if(index >= n) return 1e9;
        if(index == n-1) return 0;
        if(dp[index] != -1) return dp[index];

        int mini = 1e9;

        for(int i=index+1; i<=index+ nums[index]; i++){

            int cnt = 1 + findMinJump(i,n,nums,dp);

            if(cnt < mini) mini = cnt;
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        
        int n = nums.size();
        // vector<int> dp(n,-1);

        // return findMinJump(0,n,nums,dp);

        vector<int> dp(n+1,0);
        dp[n] = 1e9;
        dp[n-1] = 0;

        for(int i=n-2; i>=0; i--){

            int mini = 1e9;

            for(int j=i+1; j<=min(n, i+ nums[i]); j++){

                int cnt = 1 + dp[j];

                if(cnt < mini) mini = cnt;
            }

            dp[i] = mini;
        }

        return dp[0];
    }
};