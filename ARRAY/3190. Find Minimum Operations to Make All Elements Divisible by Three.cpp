class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int cnt = 0;

        for(auto &x : nums){

            if(x % 3 != 0) cnt++;
        }

        return cnt;
    }
};