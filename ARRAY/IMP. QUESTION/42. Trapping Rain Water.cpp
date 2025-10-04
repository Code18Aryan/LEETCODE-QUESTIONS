class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        int leftMax = height[0];
        int totalWater = 0;

        // Time complexity - O(2N)
        // Space complexity - O(N)

        for(int i=n-2; i>=0; i--){

            rightMax[i] = max(height[i],rightMax[i+1]);
        }

        for(int i=0; i<n; i++){

            leftMax = max(leftMax,height[i]);
            totalWater += min(leftMax,rightMax[i]) - height[i];
            
        }

        return totalWater;
    }
};