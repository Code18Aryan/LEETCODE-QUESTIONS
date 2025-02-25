class Solution {
public:

    vector<int> nearestSmallestToLeft(vector<int>&nums){

          stack<pair<int,int>> st;

          vector<int> v;
         
         int n = nums.size();
        
        for(int i=0; i<n; i++){
             
              if( st.size() == 0){
                   
                   v.push_back(-1);
              }

              else if( st.size() > 0 && st.top().first < nums[i]){
                   
                    v.push_back(st.top().second);
              }
uu
              else if( st.size() > 0 && st.top().first >= nums[i]){
                   
                    while( st.size() > 0 && st.top().first >= nums[i]){
                         
                          st.pop();
                    }

                    if( st.size() == 0) v.push_back(-1);

                    else{
                         
                          v.push_back(st.top().second);
                    }
              }


              st.push({nums[i],i});
        }


        return v;

    }


    vector<int> nearestSmallestToRight(vector<int>&nums){
         
          stack<pair<int,int>> st;

          vector<int> v;

          int n = nums.size();

          for(int i=n-1; i>=0; i--){
               
                if(st.size() == 0) v.push_back(n);

                else if( st.size() > 0 && st.top().first < nums[i]){
                     
                      v.push_back(st.top().second);
                }

                else if( st.size() > 0 && st.top().first >= nums[i]){
                     
                      while( st.size() > 0 && st.top().first >= nums[i]){
                           
                            st.pop();
                      }

                      if(st.size() == 0) v.push_back(n);

                      else{
                           
                            v.push_back(st.top().second);
                      }
                }

                st.push({nums[i],i});
          }


          reverse(v.begin(),v.end());

          return v;
    }


    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> v1 = nearestSmallestToLeft(heights);
        vector<int> v2 = nearestSmallestToRight(heights);

        int maxArea = 0;

        for(int i=0; i<n; i++){
             
            maxArea = max( maxArea ,( v2[i] - v1[i] - 1) * heights[i]);
        }

        return maxArea;
        
    }
};