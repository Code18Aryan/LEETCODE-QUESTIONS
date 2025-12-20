class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();
        int cnt = 0;
        int m = strs[0].size();

        for(int j=0; j<m; j++){

            for(int i=1; i<n; i++){

                if(strs[i][j] >= strs[i-1][j]) continue;

                cnt++;
                break;
            }
        }

        return cnt;
    }
};