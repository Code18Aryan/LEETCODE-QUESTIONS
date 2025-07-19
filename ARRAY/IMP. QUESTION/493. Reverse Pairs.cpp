class Solution {

private:

    void merge(vector<int>&nums, int low , int mid , int high){
         
          vector<int>temp;

          int left = low;
          int right = mid+1;

          while( left <= mid && right <= high){
               
                if(nums[left] <= nums[right]){
                     
                      temp.push_back(nums[left]);
                      left++;
                }

                else{
                     
                      temp.push_back(nums[right]);
                      right++;
                }
          }

          while( left <= mid){
               
                temp.push_back(nums[left]);
                left++;
          }

          while( right <= high){
               
                temp.push_back(nums[right]);
                right++;
          }

          for(int i=low; i<=high; i++){
               
              nums[i] = temp[i-low];
          }
    }


    int countReversePair(vector<int>&nums, int low, int high){
         
          int count = 0;

          if( low >= high) return count;

          int mid = low + (high - low) /2;

          count += countReversePair(nums,low,mid);
          count += countReversePair(nums,mid+1,high);
          count += countBeforeMerging(nums,low,mid,high);

          merge(nums,low,mid,high);

          return count;
    }

    int countBeforeMerging(vector<int>&nums, int low , int mid , int high){
         
          int count = 0;

          int right = mid+1;

          for(int i=low; i<=mid; i++){
               
                while( right <= high && nums[i] > 2*(long long)nums[right]){
                     
                     right++;
                }

                count += (right - (mid + 1)) ;
          }

          return count;
    }

public:

    int reversePairs(vector<int>& nums) {

        int  n = nums.size();

        int countPairs = countReversePair(nums,0,n-1);

        // Reverse Pair can be solved using 2 method one is brute force , another one is divide and conqurer method 

        // for(int i=0; i<n-1; i++){
             
        //     for(int j=i+1; j<n; j++){
                 
        //           if(nums[i] > 2*nums[j]){
                       
        //                 countReversePair++;
        //           }
        //     }
        // }


        return countPairs;
        
        
    }
};