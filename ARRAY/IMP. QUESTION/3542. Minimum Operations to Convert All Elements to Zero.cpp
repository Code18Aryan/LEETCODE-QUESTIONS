class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        stack<int> st;
        int count = 0;
        for(auto x : nums){

            while(!st.empty() && st.top() > x) st.pop();
            if(x == 0) continue;
            if(st.empty() || st.top() < x){

                st.push(x); count++;
            }
        }

        return count;
    }
};