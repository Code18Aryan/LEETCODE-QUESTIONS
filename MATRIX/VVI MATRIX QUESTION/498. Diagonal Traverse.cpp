#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        bool flag = false;

        map<int,vector<int>> mpp;

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                mpp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &x : mpp){

            vector<int> temp = x.second;
            int size = temp.size();

            if(flag){

                for(int i=0; i<size; i++){

                    ans.push_back(temp[i]);
                }
                
            }

            else{

                for(int i=size-1; i>=0; i--){

                    ans.push_back(temp[i]);
                }
            }

            flag = !flag;
        }

        return ans;
        
    }
};