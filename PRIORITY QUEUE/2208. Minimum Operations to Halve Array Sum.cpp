class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        int count = 0;
        double sum = 0;

        priority_queue<double> pq;

        for(auto &x : nums){

            sum += x;
            pq.push(x);
        }

        double halfSum = sum/2;

        while(!pq.empty()){

            if(sum <= halfSum) break;
            
            double element = pq.top();
            pq.pop();

            sum -= (element/2);
            pq.push(element/2);
            count++;
            
        }

        return count;
    }
};