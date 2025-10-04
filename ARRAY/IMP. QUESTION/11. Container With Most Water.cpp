class Solution {
public:
    int maxArea(vector<int>& height) {

      // koi bhi do point le skte hai toh farthest left, right pointer lena hai
      // to calculate how much water it can store use the same logic as trapping rain water
      // take min of both left and right and * with (j-i) which gives us width
      // if(left < or even equal to right) the i++ because we may find taller building in right side

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
