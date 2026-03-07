class Solution {
public:

    int findTallestRodHeight(int index, int diff, int n, vector<int>&rods, vector<vector<int>>&dp){

        if(index >= n){

            if(diff == 0) return 0;

            return INT_MIN;
        }

        if(dp[index][diff+5000] != -1) return dp[index][diff+5000];

        int pickFirst = rods[index] + findTallestRodHeight(index+1, diff + rods[index], n, rods,dp);
        int pickSecond = rods[index] + findTallestRodHeight(index+1, diff - rods[index], n, rods,dp);
        int pickNoOne = findTallestRodHeight(index+1, diff, n, rods,dp);

        return dp[index][diff + 5000] = max({pickFirst,pickSecond,pickNoOne});
    }


    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        vector<vector<int>> dp(n+1, vector<int>(11000,-1));

        return findTallestRodHeight(0,0,n,rods,dp) / 2;
    }
};