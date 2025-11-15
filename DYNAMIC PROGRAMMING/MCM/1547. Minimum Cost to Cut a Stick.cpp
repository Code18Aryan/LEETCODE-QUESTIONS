// Ques Link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution {

private:

    int findMinCost(int i, int j , vector<int>&nums, vector<vector<int>> &dp){
         
          if( i > j) return 0; // 

          if(dp[i][j] != -1) return dp[i][j];

          int miniCost = INT_MAX;

          for(int k=i; k<=j; k++){
                                                                                                         //  0   1     index     n-1  n
             int cost = nums[j+1] - nums[i-1] + findMinCost(i,k-1,nums,dp) + findMinCost(k+1,j,nums,dp); //  0   i       k       j    7

             miniCost = min(miniCost,cost);

          }

          return dp[i][j] =  miniCost;
    }


public:
    int minCost(int n, vector<int>& cuts) {

        int size = cuts.size(); // original Array size before including 0 and 7 at begin and end

        sort(cuts.begin(),cuts.end());

        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

       // vector<vector<int>> dp(size + 1, vector<int>(size + 1, -1)); size + 1 because i goes till size + 1 why ? becoz we add 7 at last

       //  return findMinCost(1,size,cuts,dp);

        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));  // size + 2 because 


        // Bottom - up Approach


        for(int i=size; i>=1; i--){
             
             for(int j=1; j<=size; j++){
                 
                  if(i > j) continue;

                  int miniCost = INT_MAX;

                  for(int k=i; k<=j; k++){
                                                                                                         
                  int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];

                  miniCost = min(miniCost,cost);


               }

                dp[i][j] =  miniCost;
                  
             }
        }

        return dp[1][size];
    }

};
