class Solution {
public:

    int findMaxProfit(int index, bool canBuyStock,vector<int>& prices, vector<vector<int>> &dp){

        if(index == prices.size()) return 0;
        if(dp[index][canBuyStock] != -1) return dp[index][canBuyStock];
        
        int profit = 0;

        if(canBuyStock){

            profit = max(-prices[index] + findMaxProfit(index +1, false, prices,dp), findMaxProfit(index+1, true, prices, dp));
        }

        else{

            profit = max(prices[index] + findMaxProfit(index + 1, true, prices, dp) ,findMaxProfit(index+1 , false,prices,dp));
        }

        return dp[index][canBuyStock] = profit;
    }



    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(2,-1));

        return findMaxProfit(0,1,prices,dp);
    }
};