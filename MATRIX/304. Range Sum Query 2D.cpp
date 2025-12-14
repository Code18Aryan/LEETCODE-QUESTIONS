class Solution {
  public:
    
    int findSum(vector<vector<int>>& mat, int r1, int c1, int r2, int c2){
        
        r1 = r1 + 1;
        c1 = c1 + 1;
        r2 = r2 + 1;
        c2 = c2 + 1;
        
        int bottomRight = mat[r2][c2];
        int rightSide = mat[r1-1][c2];
        int leftSide = mat[r2][c1-1];
        int topLeft = mat[r1-1][c1-1];
        
        return bottomRight - rightSide - leftSide + topLeft;
        
    }
  
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> sumMat(n+1, vector<int>(m+1,0));
        
        for(int i=0; i<n; i++){
                
            int prefix = 0;
            
            for(int j=0; j<m; j++){
                
                prefix += mat[i][j];
                int above = sumMat[i][j+1];
                
                sumMat[i+1][j+1] = prefix + above;
            }
        }
        
        for(auto &x : queries){
            
            int r1 = x[0];
            int c1 = x[1];
            int r2 = x[2];
            int c2 = x[3];
            
            int sum = findSum(sumMat,r1,c1,r2,c2);
            
            ans.push_back(sum);
        }
        
        
        return ans;
    }
};
