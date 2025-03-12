 high = mid-1;//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
  
    int solve(int n, vector<int>&cost, vector<int>&dp){
        
        if(n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int one = cost[n-1] + solve(n-1,cost,dp);
        int two = cost[n-1] + solve(n-2,cost,dp);
        
        return dp[n] = min(one,two);
    }
  
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n+1,-1);
        
        return min(solve(n,cost,dp), solve(n-1,cost,dp));
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends