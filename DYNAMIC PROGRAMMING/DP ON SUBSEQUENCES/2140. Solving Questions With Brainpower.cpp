class Solution {
public:

    typedef long long ll;

    ll solve(int index, int n, vector<vector<int>>& questions, vector<ll>&dp){

        if(index > n-1) return 0;
        if(dp[index] != -1) return dp[index];

            int points = questions[index][0];
            int power = questions[index][1];

            ll take = points + solve(index + 1 + power , n,questions,dp);
            ll notTake = solve(index + 1, n, questions,dp);


        return max(take,notTake);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();

        //vector<ll> dp(n+1,-1);

        // return solve(0,n,questions,dp);

        vector<ll> dp(n+1,0);

        for(int i=n-1; i>=0; i--){

            ll take = questions[i][0];

            if(i + 1 + questions[i][1] < n){

                take += dp[i+1+questions[i][1]];
            }

            ll notTake = dp[i+1];

            dp[i] = max(take,notTake);
        }

        return dp[0];
    }
};