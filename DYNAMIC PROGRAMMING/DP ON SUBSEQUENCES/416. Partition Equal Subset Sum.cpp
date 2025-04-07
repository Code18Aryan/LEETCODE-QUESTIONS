class Solution {
public:
    // Recursion Plus Memoization with 2D dp Matrix 

    bool findSubsetSum(int n, int sum, vector<int>&nums, vector<vector<int>>&dp){

        if(sum == 0) return true;
        if(n == 0 && sum > 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];

        if(nums[n-1] <= sum){

            bool take = findSubsetSum(n-1,sum-nums[n-1],nums,dp);
            bool notTake = findSubsetSum(n-1,sum,nums,dp);

            return dp[n][sum] = take || notTake;
        }

        else{

            return dp[n][sum] = findSubsetSum(n-1,sum,nums,dp);
        }
    }



    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 == 1){

            return false;
        }

        else{

            // vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));

            // return findSubsetSum(n,sum/2,nums,dp);



            // Tabulation Time complexity - O(n*m) 
            //            space complexity - O(n*m) 

            vector<vector<int>> dp(n+1, vector<int>(sum+1,0));

            for(int i=0; i<n+1; i++){

                dp[i][0] = 1;
            }

            for(int i=1; i<n+1; i++){

                for(int j=1; j<sum+1; j++){

                    if(nums[i-1] <= j){

                        bool take = dp[i-1][j-nums[i-1]];
                        bool notTake = dp[i-1][j];

                        dp[i][j] = take || notTake;
                    }

                    else dp[i][j] = dp[i-1][j];
                }

            }
            return dp[n][sum/2];

        }
    }
};