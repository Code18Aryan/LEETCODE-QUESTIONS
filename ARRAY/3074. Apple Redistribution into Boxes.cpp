class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        priority_queue<int> pq;
        
        for(auto &x : capacity) pq.push(x);

        int totalApple = accumulate(apple.begin(),apple.end(),0);
        int cnt = 0;

        while(!pq.empty()){

            int currCapacity = pq.top();
            pq.pop();
            cnt++;
            totalApple -= currCapacity;
            if(totalApple <= 0) break;
        }

        return cnt;
    }
};