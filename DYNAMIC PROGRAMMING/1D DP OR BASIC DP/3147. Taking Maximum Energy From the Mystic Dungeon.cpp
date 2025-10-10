class Solution {
public:

    // Recursive + Memoization for each instance of i
    // Time complexity - O(n) for loop + O(n/k) for recursion total O(n) * O(n/k)
    // Space complexity - O(n) for dp array + recursion stack space

    int findMaxEnergy(int index, int n, int k, vector<int>&dp, vector<int>&energy){

        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];

        int currentEnergy = energy[index];

        if(index + k < n){

            currentEnergy += findMaxEnergy(index +k,n,k,dp,energy);
        } 

        return dp[index] = currentEnergy;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        vector<int> dp(n,-1);

        int maxEnergy = -1e9;

        /*

        for(int i=0; i<n; i++){

            int curr = findMaxEnergy(i,n,k,dp,energy);
            maxEnergy = max(maxEnergy,curr);
        }

        */

        // Tabulation for removing extra stack space for recursion

        for(int i=n-1; i>=0; i--){

            int currentEnergy = energy[i];

            if(i + k < n){

                currentEnergy += dp[i+k];
            }

            dp[i] = currentEnergy;

            maxEnergy = max(maxEnergy,dp[i]);
        }
    

        return maxEnergy;
    }
};