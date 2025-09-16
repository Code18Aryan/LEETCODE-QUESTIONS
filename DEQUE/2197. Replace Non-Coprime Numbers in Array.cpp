class Solution {
public:

    int findGcd(int a , int b){

        if(b == 0) return a;

        return findGcd(b, a % b);
    }

    typedef long long ll;

    vector<int> replaceNonCoprimes(vector<int>& nums) {

        deque<long long> dq;
        vector<int> ans;

        for(auto &x : nums){

            ll current = x;

            while(!dq.empty()){

                ll gcd = findGcd(dq.back(),current);

                if(gcd == 1) break;

                current = (dq.back()/ gcd) * current;
                dq.pop_back();
            }

            dq.push_back(current);
            
        }

        for(auto &x : dq){

            ans.push_back((int)x);
        }

        return ans;
    }
};