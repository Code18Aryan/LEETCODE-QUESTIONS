class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int minDiff = 1e9;
        int ans = 0;

        for(int i=0; i<n; i++){

            if(i > 0 && nums[i-1] == nums[i]) continue;

            int j = i+1;
            int k = n-1;

            while( j < k){

                int sum = nums[i] + nums[j] + nums[k];

                int currDiff = abs(target - sum);

                if(currDiff < minDiff){

                    ans = sum;
                    minDiff = currDiff;
                }

                else if(minDiff == currDiff){

                    ans = max(ans,sum);
                }

                if(sum <= target) j++;
                else k--;
            }
        }

        return ans;
    }
};