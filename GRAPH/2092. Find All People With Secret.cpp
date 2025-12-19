class Solution {
public:

    typedef pair<int,int> p;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        unordered_map<int,vector<vector<int>>> adj;

        for(auto &x : meetings){

            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> vis(n,0);
        vector<int> ans;

        pq.push({0,firstPerson});
        pq.push({0,0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int person = it.second;

            if(vis[person]) continue;
            vis[person] = true;

            for(auto &x : adj[person]){

                if(!vis[x[0]] && time <= x[1]){

                    pq.push({x[1],x[0]});
                }
            }
        }

        for(int i=0; i<n; i++){

            if(vis[i]) ans.push_back(i);
        }

        return ans;
    }
};