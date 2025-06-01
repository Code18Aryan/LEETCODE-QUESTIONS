class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n) {
        
        unordered_map<int,int> mpp;
        
        int cnt = 0;
        
        for(auto x : mat2){
            
            for(auto y : x){
                
                mpp[y]++;
            }
        }
        
        for(auto x : mat1){
            
            for(auto y : x){
                
                int target = n - y;
                
                if(mpp.find(target) != mpp.end()){
                    
                    cnt += mpp[target];
                }
            }
        }
        
        return cnt;
    }
};