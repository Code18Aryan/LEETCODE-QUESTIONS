problem link https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        // ----- Brute force ----
        // take sortedArray and rotate it n time and check if current array == given array

        /*
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());

        while(n--){

            rotate(temp.begin(),temp.end()-1,temp.end());

            if(temp == nums) return true;
        }

        return false;

        */

        // -------Better Solution ---- if array is rotated then its prev element is > only one time 

        int peak = 0;

        for(int i=1; i<n; i++){

            if(nums[i-1] > nums[i]) peak++;

            if(peak > 1) return false;
        }

        if(nums[n-1] > nums[0]) peak++;

        return peak <= 1 ? true : false;
        
    }
};