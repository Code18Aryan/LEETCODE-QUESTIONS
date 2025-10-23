class Solution {
public:

    typedef pair<int,pair<int,int>> p;
  
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       
       priority_queue<p> pq;
       vector<vector<int>> ans;
       
       for(auto &it : points){
           
           int x = it[0];
           int y = it[1];
           
           int distance = (x * x) + (y * y);
           
           pq.push({distance,{x,y}});
           
           if(pq.size() > k) pq.pop();
       }
       
       while(!pq.empty()){
           
           ans.push_back({pq.top().second.first,pq.top().second.second});
           pq.pop();
       }
       
       return ans;
    }
};