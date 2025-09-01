#include <bits/stdc++.h>
using namespace std;

class A{

    public:

    int findBouquets(vector<int>&nums, int day, int k){

        int numberOfBouquets = 0;
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] <= day){

                cnt++;

            }

            else{

                numberOfBouquets += (cnt / k);
                cnt  = 0;
            }

        }

        numberOfBouquets += (cnt /k);

        return numberOfBouquets;
    }


};


class Solution {
public:
    int roseGarden(int n,vector<int> nums, int k, int m) {

       // if((m * k )> (nums.size())) return -1;
    
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;

        A obj;

        while(low <= high){

            int mid = low + (high-low)/2;

            int bouquets  = obj.findBouquets(nums,mid,k);

            if(bouquets >= m){

                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return ans;
    
    }
};