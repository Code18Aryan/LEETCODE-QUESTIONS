class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();
        int element;
        int cnt = 0;
        
        for(int i=0; i<n; i++){

            if(cnt == 0){

                element = nums[i];
                cnt++;
            }

            else if(nums[i] == element){

                cnt++;
            }

            else cnt--;
        }

        int majorityCnt = 0;

        for(auto &x : nums){

            if(x == element){

                majorityCnt++;
            }
        }

        cnt = 0;

        for(int i=0; i<n; i++){

            int n1 = (i-0+1);
            int n2 = (n-i-1);

            if(nums[i] == element){

                cnt++;
            }

            int remain = majorityCnt - cnt;

            if( cnt > n1/2 && remain > n2/2) return i;
        }

        return -1;
        
    }
};