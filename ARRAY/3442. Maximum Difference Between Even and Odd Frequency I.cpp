class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char,int> mpp;

        int maxi = INT_MIN, mini = INT_MAX;

        for(auto &x : s) mpp[x]++;

        for(auto &x : mpp){

            if(x.second == 0) continue;

            if(x.second % 2 == 1){

                maxi = max(maxi,x.second);
            }

            else mini = min(mini,x.second);
        }

        return maxi - mini;

    }
};