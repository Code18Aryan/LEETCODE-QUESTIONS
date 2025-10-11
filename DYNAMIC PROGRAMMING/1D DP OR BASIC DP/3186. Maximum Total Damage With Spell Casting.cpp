// Ques Link - https://leetcode.com/problems/maximum-total-damage-with-spell-casting/?envType=daily-question&envId=2025-10-11


class Solution {
public:

    typedef long long ll;

    ll findMaxPower(int i, int n, vector<int>&power, vector<ll>&dp, unordered_map<ll,ll>&mpp){
        
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];


        int nextElement = lower_bound(power.begin() +  i + 1, power.end(), power[i] + 3) - power.begin();

        ll pick = (power[i] * mpp[power[i]] )+ findMaxPower(nextElement,n,power,dp,mpp);
        ll notPick = findMaxPower(i+1,n,power,dp,mpp);

        return dp[i] = max(pick,notPick);
    }

    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<ll,ll> mpp;
        for(auto &x : power) mpp[x]++;
        sort(power.begin(),power.end());
        vector<ll> dp(power.size(),-1);

        return findMaxPower(0,power.size(),power,dp,mpp);
    }

};
