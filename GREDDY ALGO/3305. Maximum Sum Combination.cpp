class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int n = a.size(), m = b.size();
        
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({a[n-1] + b[m-1], {n-1,m-1}});
        
        set<pair<int,int>> st;
        st.insert({n-1,m-1});
        
        vector<int> ans;
        
        while(k--){
            
            auto x = pq.top();
            int currentSum = x.first;
            int i = x.second.first;
            int j = x.second.second;
            pq.pop();
            
            ans.push_back(currentSum);
            
            if(i-1 >= 0 && st.find({i-1,j}) == st.end()){
                
                st.insert({i-1,j});
                pq.push({a[i-1] + b[j],{i-1,j}});
            }
            
            if(j-1 >= 0 && st.find({i,j-1}) == st.end()){
                
                st.insert({i,j-1});
                pq.push({a[i] + b[j-1],{i,j-1}});
            }
            
        }
        
        return ans;
        
    }
};