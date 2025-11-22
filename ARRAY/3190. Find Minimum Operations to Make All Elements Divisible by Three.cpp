// QuesLink - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-22

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
