// Ques Link - https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        unordered_map<int,int> mpp;

        for(auto &x : nums){

            mpp[((x % value) + value) % value]++;
        }


        for(int i=0; i<nums.size(); i++){

            if(mpp.find(i % value) != mpp.end()){

                mpp[i % value]--;
                if(mpp[i % value] == 0) mpp.erase(i % value);
            }
            
            else return i;
        }

        return nums.size();
    }

};
