class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        // Brute force check all subarray for inc and dec if cond. fail break;

        

        int n = nums.size();

        /*

        int result = 0;

        for(int i=0; i<n; i++){

            int inc = 1;
            int j = i+1;

            while(j < n && nums[j] > nums[j-1]){

                inc++;
                j++;
            }

            int dec = 1;
            j = i+1;

            while( j < n && nums[j] < nums[j-1]){

                 dec++;
                 j++;
            }

            result = max({inc,dec,result});
        }

        return result;

        */


        // Optimal suppose if subarray is inc then their is not a chance that subaray is dec

        int inc = 1;
        int dec = 1;
        int result = 1;

        for(int i=1; i<n; i++){

            if(nums[i] > nums[i-1]){

                inc++;
                dec = 1;

                result = max(result,inc);
            }

            else if(nums[i] < nums[i-1]){

                dec++;
                inc = 1;

                result = max(result,dec);
            }

            else{

                inc = 1;
                dec = 1;
            }

        }

        return result;
        
    }
};