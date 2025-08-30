class Solution {
public:
    int maxArea(vector<int>& height) {

      int maxCapacity = 0;
      
      int low = 0, high = height.size()-1;

      while( low < high){
         
          int waterCapacity = min(height[low] , height[high]) * (high -low);

          maxCapacity = max(maxCapacity , waterCapacity);

          if(height[low] <= height[high]) low++;

          else high--;
      }

      return maxCapacity;
        
    }
};