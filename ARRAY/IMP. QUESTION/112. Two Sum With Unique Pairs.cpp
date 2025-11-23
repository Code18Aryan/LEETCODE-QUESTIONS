// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        
        int i = 0;
        int j = arr.size()-1;
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        
        while(i < j){
            
            int sum = arr[i] + arr[j];
            
            if(sum == 0){
                
                ans.push_back({arr[i],arr[j]});
                i++;
                j--;
                
                while(i < j && arr[i] == arr[i-1]){
                    
                    i++;
                }
                
                while( i < j && arr[j] == arr[j+1]){
                    
                    j--;
                }
            }
            
            else if(sum < 0) i++;
            else j--;
        }
        
        return ans;
    }
};