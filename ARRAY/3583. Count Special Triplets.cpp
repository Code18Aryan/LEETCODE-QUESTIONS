class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int ,int> right, left;
        long long cnt = 0;
        int mod = 1e9 + 7;

        for(auto &x : nums) right[x]++;

        for(int i=0; i<n; i++){

            right[nums[i]]--;

            int target = nums[i] * 2;
            
            if(left.find(target) != left.end() && right.find(target) != right.end()){

                cnt = (cnt + 1LL * left[target] * right[target]) % mod;

            }

            left[nums[i]]++;
        }

        return (int)cnt;
    }
};