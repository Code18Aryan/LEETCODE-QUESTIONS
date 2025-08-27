class Solution {

private:

  int findSmallestDivisor(int divisor, vector<int>&nums){

        int n = nums.size();

        int sum = 0;

        for(int i=0; i<n; i++){

            sum += ceil(double(nums[i])/ double(divisor));
        }

        return sum;
  }


public:
  int smallestDivisor(vector<int> &nums, int limit) {
       
       int low = 1;
       int high = *max_element(nums.begin(),nums.end());
       int ans = -1;

       while(low <= high){

            int mid = (low + high)/2;

            int currentSamllestDivisor = findSmallestDivisor(mid,nums);

            if(currentSamllestDivisor <= limit){

                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
       }

       return ans;
    }
};