// Ques Link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/


class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        unordered_set<int> st;
        vector<int> ans;

        for(auto &x : matrix){

            int mini = 1e9;

            for(auto &y : x){

                mini = min(mini,y);
            }

            st.insert(mini);
        }

        for(int i=0; i<matrix[0].size(); i++){

            int maxi = -1e9;

            for(int j=0; j<matrix.size(); j++){

                maxi = max(maxi,matrix[j][i]);
            }

            if(st.find(maxi) != st.end()){

                ans.push_back(maxi);
            } 
        }

        return ans;
    }
};