class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        unordered_map<int,int> mpp;

        vector<vector<int>> ans;

        for(auto x : nums1){

            int id = x[0];
            int val = x[1];

            mpp[id] = val;
        }

        for(auto x : nums2){

            int id = x[0];
            int val = x[1];

            if(mpp.count(id)){

                int preValue = mpp[id];
                mpp[id] = preValue + val;
            }

            else mpp[id] = val;
        }

        for(auto x : mpp){

            ans.push_back({x.first,x.second});
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};