class Solution{

private:

    bool hasElement(vector<int>&nums, int target){

        int low = 0;
        int high = nums.size()-1;

        while(low <= high){

            int mid = low +  (high-low)/2;

            if(nums[mid] == target) return true;

            if(nums[mid] < target) low = mid+1;
            
            else high = mid-1;
        }

        return false;
    }


public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){

            int first = mat[i][0];
            int last = mat[i][m-1];

            if(first <= target && target <= last){

                if(hasElement(mat[i],target)) return true;
            }
        }

        return 0;
    }
};