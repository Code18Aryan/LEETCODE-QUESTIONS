#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

int shortestPath(vector<vector<int>>&mat, int src, int dest){
  
    unordered_map<int,vector<vector<int>>> adj;
    int n = mat.size();
    
    for(int i=0; i<n; i++){
      
      for(int j=0; j<n; j++){
        
        if(i != j && mat[i][j] != -1){
          
            adj[i].push_back({j,mat[i][j]});
        }
      }
    }
    
    vector<int> distance(n,1e9);
    distance[src] = 0;
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,src});
    
    while(!pq.empty()){
      
      auto it = pq.top();
      pq.pop();
      
      int dist = it.first;
      int node = it.second;
      
      for(auto &x : adj[node]){
        
        int v = x[0];
        int wt = x[1];
        
        if(dist + wt < distance[v]){
          
          distance[v] = dist + wt;
          pq.push({dist+wt,v});
        }
      }
    }
    
    return distance[dest];
}


void flyodWarshall(vector<vector<int>> &mat){
  
  int n = mat.size();
  
  for(int i=0; i<n; i++){
    
    for(int j=0; j<n; j++){
      
      if(mat[i][j] == -1) mat[i][j] = 1e9;
    }
  }
  
  for(int k=0; k<n; k++){
    
    for(int i=0; i<n; i++){
      
      for(int j=0; j<n; j++){
        
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }
  
  for(int i=0; i<n; i++){
    
    for(int j=0; j<n; j++){
      
      if(mat[i][j] == 1e9) mat[i][j] = -1;
    }
  }
  
  for(int i=0; i<n; i++){
    
    for(int j=0; j<n; j++){
      
      cout<<mat[i][j]<<" ";
    }
    
    cout<<endl;
  }
}

int main(){
  
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   vector<vector<int>> mat1 = {
     
      {0,5,-1,10},
      {-1,0,3,-1},
      {-1,-1,0,1},
      {-1,-1,-1,0}
     
   };
   
   vector<vector<int>> mat2 = {
    {0,  2, -1,  6, -1},
    {-1, 0,  3,  8,  5},
    {-1, -1, 0, -1,  7},
    {-1, -1, -1, 0,  9},
    {-1, -1, -1, -1, 0}
};
   
   vector<vector<int>> mat3 = {
    {0,  4, -1},
    {-1, 0, -1},
    {-1, -1, 0}
};

  int n = 1;

  vector<pair<int,int>> p = { {0,3},{0,4},{0,2} };
  
  for(auto &x : p){
    
    int src = x.first;
    int dest = x.second;
    
    if(n == 1){
      
      cout<<shortestPath(mat1,src,dest)<<endl;
      flyodWarshall(mat1);
      cout<<endl;
    }
    
    else if(n == 2){
      
      cout<<shortestPath(mat2,src,dest)<<endl;
      flyodWarshall(mat2);
      cout<<endl;
    }
    
    else{
      
      cout<<shortestPath(mat3,src,dest)<<endl;
      flyodWarshall(mat3);
      cout<<endl;
    }
    
    n++;
  }
  
}