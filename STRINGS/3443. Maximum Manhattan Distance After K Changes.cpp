class Solution {
public:
    int maxDistance(string s, int k) {

        int n = s.size();

         int north = 0, south = 0, east = 0, west = 0, ans = 0, maxi = 0;

        unordered_map<char,int> mpp;

        for(int i=0; i<n; i++){

            mpp[s[i]]++;
        }

        for(int i=0; i<n; i++){

            char ch = s[i];

            if(ch == 'N') north++;
            if(ch == 'S') south++;
            if(ch == 'E') east++;
            if(ch == 'W') west++;

            int x = abs(north - south);
            int y = abs(west - east);

            int m = x + y;
            int dist = m + min(2*k, i+1-m);

            ans = max(ans,dist);
        }

       
        return ans;
    }
};