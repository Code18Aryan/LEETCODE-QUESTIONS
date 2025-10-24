// Ques Link - https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution {
public:

    typedef pair<int,int> p;

    bool isPossible(vector<int>& nums) {
        
        int k = 3;
        priority_queue<p,vector<p>,greater<p>> pq;

        for(auto &x : nums){

            while(!pq.empty() && pq.top().first + 1 < x){

                if(pq.top().second < k) return 0;
                pq.pop();
            }

            if(!pq.empty() && pq.top().first + 1 == x){

                auto it = pq.top();
                pq.pop();

                pq.push({x,it.second+1});
            }

            else pq.push({x,1});
        }

        while(!pq.empty()){

            if(pq.top().second < k) return 0;

            pq.pop();
        }

        return 1;
    }

};
