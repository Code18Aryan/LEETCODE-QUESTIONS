class Solution {
public:

    int findSub(int n, int m, string s, string t, vector<vector<int>> &dp){

        if(m == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];

        if(s[n-1] == t[m-1]){

            int pick = findSub(n-1,m-1,s,t,dp);
            int notPick = findSub(n-1,m,s,t,dp);

            return dp[n][m] = pick + notPick;
        }

        else return dp[n][m] = findSub(n-1,m,s,t,dp);
    }


    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        // return findSub(n,m,s,t,dp);

        vector<vector<double>> dp(n+1, vector<double>(m+1,0));

        for(int i=0; i<n+1; i++){

            dp[i][0] = 1;
        }

        for(int i=1; i<n+1; i++){

            for(int j=1; j<m+1; j++){

                if(s[i-1] == t[j-1]){

                    double pick = dp[i-1][j-1];
                    double notPick = dp[i-1][j];

                    dp[i][j] = pick + notPick;
                }

                else{

                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};