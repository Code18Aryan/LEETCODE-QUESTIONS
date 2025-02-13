class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long,vector<long long>,greater<long long>> pq(nums.begin(),nums.end());

        int cnt = 0;

        while(pq.top() < k && pq.size() >= 2){

            long long  first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            long long element = first * 2 + second;

            pq.push(element);

            cnt++;
        }

        return cnt;
        
    }
};