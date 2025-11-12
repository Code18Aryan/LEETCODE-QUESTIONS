class Solution {
public:

    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int countOne = 0;

        for(auto &x : nums){

            if(x == 1) countOne++;
        }

        if(countOne > 0) return n - countOne;

        int minOperation = 1e9;

        for(int i=0; i<n-1; i++){
            
            int x = nums[i];

            for(int j=i+1; j<n; j++){

                 x = __gcd(x,nums[j]);

                if(x == 1){

                    minOperation = min(minOperation, j-i);
                    break;
                }

            }
        }

        return minOperation == 1e9 ? -1 : minOperation + (n-1);
    }
};