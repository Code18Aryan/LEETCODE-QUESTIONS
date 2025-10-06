class Solution {
  public:
  
    vector<int> dr = {-2,-1,+1,+2,+2,+1,-1,-2};
    vector<int> dc = {1,2,2,1,-1,-2,-2,-1};
    
    void print(vector<vector<int>>&mat){
        
        for(auto x : mat){
            
            for(auto y : x){
                
                cout<<y<<" ";
            }
            
            cout<<endl;
        }
    }
    

    bool visit(int row, int col, int n, vector<vector<int>>&board, int move){
        
        board[row][col] = move;
        
        if(move == (n*n)-1){
            
            //print(board); 
            
           return true;
        }
        
        for(int i=0; i<8; i++){
            
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            
            if(nRow < n && nCol < n && nRow >= 0 && nCol >= 0 && board[nRow][nCol] == -1){
            
                
                if(visit(nRow,nCol,n,board,move+1)) return true;
                
            }
        }
        
        board[row][col] = -1;
        
        return false;
    }
  
    vector<vector<int>> knightTour(int n) {
       
       vector<vector<int>> board(n, vector<int>(n,-1));
       
       if(visit(0,0,n,board,0)) return board;
       
       return {};
        
    }
};