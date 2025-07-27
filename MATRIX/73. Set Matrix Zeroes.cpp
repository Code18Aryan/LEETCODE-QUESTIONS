class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == 0){
                    
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(rows[i] == 1 || cols[j] == 1){
                    
                    mat[i][j] = 0;
                }
            }
        }
    }
};