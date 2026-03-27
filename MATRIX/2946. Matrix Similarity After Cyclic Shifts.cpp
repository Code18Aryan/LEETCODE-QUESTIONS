class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> first = mat;
        
        
        for(int i=0; i<m; i++){
             
             if( i%2 == 1){
                  
                 rotate(mat[i].rbegin() , mat[i].rbegin() + (k % n), mat[i].rend());
             }
            
            else{
                
                rotate(mat[i].begin() , mat[i].begin() + (k % n), mat[i].end());
                
                
            }
        }
        
        
        return mat == first;
        
        
        
    }
};