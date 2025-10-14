class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(2*k > n) return false;
        vector<int> increasing(n,1);

        for(int i=1; i<n; i++){

            if(nums[i] > nums[i-1]){

                increasing[i] = increasing[i-1] + 1;
            }

            else increasing[i] = 1;
        }

        for(int i=0; i<n-k; i++){

            if(increasing[i] >= k && increasing[i+k] >= k) return true;
        }

        return false;
    }
};


//Brute Force using two std::deque



class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        if((2*k) > n) return false;

        deque<int> left,right;

        for(int i=0; i<n-k; i++){

            if(left.empty()) left.push_back(nums[i]);
            else if(!left.empty() && left.back() < nums[i]) left.push_back(nums[i]);
            else{

                while(!left.empty()) left.pop_back();
                while(right.size() > 1) right.pop_front();

                left.push_back(nums[i]);
            }

            if(right.empty()) right.push_back(nums[i+k]);
            else if(!right.empty() && right.back() < nums[i+k]) right.push_back(nums[i+k]);
            else{

                while(!right.empty()) right.pop_back();
                while(left.size() > 1) left.pop_front();

                right.push_back(nums[i+k]);
            }

            if(left.size() == k && right.size() == k) return true;
        }

        return false;

    }
};

