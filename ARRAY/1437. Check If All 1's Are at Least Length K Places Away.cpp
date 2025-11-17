class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int n = nums.size();
        int j = 0;

        for(int i=0; i<n; i++){

            if(nums[i] == 1){

                j = i;
                break;
            }
        }

        for(int i=j+1; i<n; i++){

            if(nums[i] == 0) continue;

            else{

                int length = i-j-1;
            
                if(length < k) return false;
                j = i;
            }
        }

        return true;
    }
};