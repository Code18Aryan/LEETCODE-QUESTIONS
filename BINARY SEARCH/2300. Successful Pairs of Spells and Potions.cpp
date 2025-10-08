class Solution {
public:

    typedef long long ll;

    int findPairs(vector<int>&nums, int spells, ll success){

        int low = 0;
        int high = nums.size()-1;
        int index = nums.size();

        while(low <= high){

            int mid = low + (high-low)/2;

            int potion = nums[mid];

            if((long long) spells * (long long) potion >= success){

                index = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return nums.size() - index;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        // Brute force Approach - use two loop and check spells[i] * potions[j] >= succsess or not make a cnt variable output j loop and after j loop store in a ans[i] 
        
        int n = spells.size();
        vector<int> ans(n);
        sort(potions.begin(),potions.end());

        for(int i=0; i<n; i++){

            int pairs = findPairs(potions,spells[i],success);

            ans[i] = pairs;
        }

        return ans;
    }
};