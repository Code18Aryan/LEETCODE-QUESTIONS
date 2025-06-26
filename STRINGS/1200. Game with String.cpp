class Solution {
  public:
    int minValue(string &s, int k) {
        
        int n = s.size();
        
        unordered_map<char,int> mpp;
        int sum = 0;
        
        
        for(auto x : s){
            
            mpp[x]++;
        }
        
        priority_queue<int> pq;
        
        for(auto x : mpp){
            
            int freq = x.second;
            
            pq.push(freq);
        }
        
        while(k && !pq.empty()){
            
            int freq = pq.top();
            pq.pop();
            
            freq--;
            k--;
            
            if(freq) pq.push(freq);
        }
        
        while(!pq.empty()){
            
            int x = pq.top();
            pq.pop();
            
            int sq = pow(x,2);
            
            sum += sq;
            
        }
        
        return sum;
    }
};