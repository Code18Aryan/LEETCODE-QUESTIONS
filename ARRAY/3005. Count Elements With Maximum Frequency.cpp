class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        int cnt = 0;
        int maxiFreq = 0;

        for(auto &x : nums) mpp[x]++;

        for(auto &x : mpp){

            maxiFreq = max(maxiFreq, x.second);
        }

        for(auto &x : mpp){

            if(x.second == maxiFreq){

                cnt += x.second;
            }
        }

        return cnt;
    }
};