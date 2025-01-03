class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        priority_queue<int> pq;
        pq.push(values[0]);

        int cnt = 0;

        int maxiValue = INT_MIN;

        for(int i=1; i<values.size(); i++){

            maxiValue = max(maxiValue , values[i] - i + pq.top());

            pq.push(values[i] + i);
        }

    
        return maxiValue;
        
    }

    
};