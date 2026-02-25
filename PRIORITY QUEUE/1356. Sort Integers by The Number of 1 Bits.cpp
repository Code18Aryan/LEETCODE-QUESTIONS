class Solution {
public:

    int countBits(int n){

        int cnt = 0;

        while(n){

            if(n & 1) cnt++;
            n /= 2;
        }

        return cnt;
    }

    typedef pair<int,int> p;

    vector<int> sortByBits(vector<int>& arr) {
        
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> ans;

        for(auto &x : arr){

            int bitCount = countBits(x);
            pq.push({bitCount,x});
        }

        while(!pq.empty()){

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};