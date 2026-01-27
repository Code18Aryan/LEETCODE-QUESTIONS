class Solution {
  public:
  
    vector<int> dr = {-1,0,+1,0};
    vector<int> dc = {0,+1,0,-1};
    
    bool doesContainWord(int index,int i, int j,int n, int m, vector<vector<char>>&mat, string &word){
        
        if(index == word.size()-1){
            
            return true;
        }
        
        char prevChar = mat[i][j];
        
        for(int k=0; k<4; k++){
            
            int nRow = i + dr[k];
            int nCol = j + dc[k];
            
            if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && mat[nRow][nCol] == word[index+1]){
                
                mat[i][j] = '.';
                
                if(doesContainWord(index+1,nRow,nCol,n,m,mat,word)){
                    
                    return true;
                }
                
                mat[i][j] = prevChar;
               
            }
        }
        
        return false;
        
    }
  
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        
        int n = mat.size();
        int m = mat[0].size();
        int size = word.size();
        
        if(size == 0 || size > (m*n)) return true;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == word[0]){
                    
                    if(doesContainWord(0,i,j,n,m,mat,word)){
                        
                        return true;
                    }
                }
            }
        }
        
        
        
        return false;
        
    }
};