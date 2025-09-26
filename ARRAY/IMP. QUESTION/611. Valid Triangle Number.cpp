class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        /* we need to find triplet which statisfy triangle condition i.e sum of two side is > third 
        size a + b > c and b + c > a and a + c > b
        brute force use three loop time complexity O(n3)

        Optimal -> if we sort the array and take 0th 1th 2nd as a,b,c then c > b > a
        now look at conditon a + b > c and( a + c > b , b + c > a ) which will always be true
        because we sort the array and c will ways > a and b

        */

        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());

        for(int i=n-1; i>=2; i--){

            int low = 0;
            int high = i-1;

            while(low < high){

                if(nums[low] + nums[high] > nums[i]){

                    cnt += (high-low);
                    high--;
                }

                else low++;
            }
        }

        return cnt;

    }
};