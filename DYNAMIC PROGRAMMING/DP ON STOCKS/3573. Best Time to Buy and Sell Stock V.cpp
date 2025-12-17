class Solution {
public:

    typedef long long ll;

    ll findMaxProfit(int index, int state, int currTransaction,vector<int>&prices, int k, 
    vector<vector<vector<ll>>> &dp){

        if (index == prices.size()){
            if(state == 0) return 0;
            return LLONG_MIN / 2;
        }

        if(currTransaction == k) {
            if(state == 0) return 0;
            return LLONG_MIN / 2;
        }

        ll profit = 0LL;

        if(state == 0){

            profit = max({-prices[index] + findMaxProfit(index+1,1,currTransaction,prices,k,dp), 
            prices[index] + findMaxProfit(index+1, 2,currTransaction,prices,k,dp),
            findMaxProfit(index+1,0,currTransaction,prices,k,dp)});
        } 

        else if(state == 1){

            profit = max(prices[index] + findMaxProfit(index+1,0,currTransaction+1,prices,k,dp),
            findMaxProfit(index+1,1,currTransaction,prices,k,dp)); 
        }

        else{

            profit = max(-prices[index] + findMaxProfit(index+1,0,currTransaction+1,prices,k,dp),
            findMaxProfit(index+1,2,currTransaction,prices,k,dp));
        }

        return dp[index][state][currTransaction] = profit;
    }

    long long maximumProfit(vector<int>& prices, int K) {
        
        int n = prices.size();
        //vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (3, vector<ll>(k+1,-1)));
        //return findMaxProfit(0,0,0,prices,k,dp);

        long long dp[1001][501][3];

        for (int k=0; k<=K; k++) {
            dp[n][k][0] = 0;
            dp[n][k][1] = INT_MIN;
            dp[n][k][2] = INT_MIN;
        }

        
        for (int i=n-1; i>=0; i--){
            for (int k=0; k<=K; k++){

                dp[i][k][0] = dp[i + 1][k][0];

                if (k>0){

                    dp[i][k][0] = max(
                        dp[i][k][0],
                        max(
                            -prices[i] + dp[i + 1][k][1], // buy
                             prices[i] + dp[i + 1][k][2]  // short sell
                        )
                    );
                }

                dp[i][k][1] = dp[i + 1][k][1]; // hold
                if (k > 0) {
                    dp[i][k][1] = max(
                        dp[i][k][1],
                        prices[i] + dp[i + 1][k - 1][0]  // sell
                    );
                }

                dp[i][k][2] = dp[i + 1][k][2]; // hold

                if (k>0){

                    dp[i][k][2] = max(
                        dp[i][k][2],
                        -prices[i] + dp[i + 1][k - 1][0] // buy back
                    );
                }
            }
        }

        return dp[0][K][0];
    }
};