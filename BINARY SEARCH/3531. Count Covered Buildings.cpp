class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int,vector<int>> rows, cols;
        int cnt = 0;

        for(auto &x : buildings){

            rows[x[0]].push_back(x[1]);
            cols[x[1]].push_back(x[0]);
        }

        for(auto &x : rows) sort(x.second.begin(),x.second.end());
        for(auto &x : cols) sort(x.second.begin(),x.second.end());

        for(auto &b : buildings){

            int x = b[0];
            int y = b[1];

            auto &row = rows[x];
            auto &col = cols[y];

            auto it = lower_bound(row.begin(),row.end(),y);
            auto it2 = lower_bound(col.begin(),col.end(),x);

            bool left = (it != row.begin());
            int right = (it+1 != row.end());
            int top = (it2 != col.begin());
            int bottom = (it2 +1 != col.end());

            if(left && right && top && bottom ) cnt++;
        }

        return cnt;

    }
};