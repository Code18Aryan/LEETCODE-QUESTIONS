// Ques Link - https://leetcode.com/problems/ones-and-zeroes/description/?envType=daily-question&envId=2025-11-11
class Solution {
public:
    int findMaxCount(int index, int size, vector<string>&str, int m, int n, vector<vector<vector<int>>>&dp){

        if(index >= size) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];

        int zero = count(str[index].begin(),str[index].end(),'0');
        int one = str[index].size() - zero;

        int take = 0;
        if (m >= zero && n >= one){
            take = 1 + findMaxCount(index + 1, size, str, m - zero, n - one, dp);
        }
        int notTake = findMaxCount(index + 1, size, str, m,n,dp);

        return dp[index][m][n] = max(take,notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size= strs.size();
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>> (m+1, vector<int>(n+1,-1)));

        return findMaxCount(0,size,strs,m,n,dp);
    }

};
