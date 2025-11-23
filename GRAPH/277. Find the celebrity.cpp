class Solution {
  public:
    int celebrityy(vector<vector<int>>& mat) {
        
        vector<int> inDegree(mat.size(),0);
        vector<int> outDegree(mat.size(),0);
        
        for(int i=0; i<mat.size(); i++){
            
            for(int j=0; j<mat.size(); j++){
                
                if(i != j && mat[i][j] == 1){
                    
                    inDegree[j]++;
                    outDegree[i]++;
                }
            }
        }
        
        for(int i=0; i<mat.size(); i++){
            
            if(inDegree[i] == mat.size()-1 && outDegree[i] == 0) return i;
        }
        
        return -1;
    }
    
    int celebrity(vector<vector<int>>& mat) {
        
        int i = 0;
        int j = mat.size()-1;
        
        while(i < j){
            
            if(mat[i][j] == 1){
                
                i++;
            }
            
            else j--;
        }
        
        int ans = i;
        
        for(int k=0; k<mat.size(); k++){
            
            if(k == ans) continue;
            
            if(mat[ans][k] == 1) return -1;
            if(mat[k][ans] == 0) return -1;
        }
        
        return ans;
    }
    
    
    
};