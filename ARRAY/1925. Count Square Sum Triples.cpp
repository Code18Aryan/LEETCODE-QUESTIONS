class Solution {
public:
    int countTriples(int n) {
        
        int cnt = 0;

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){

               int a2 = i*i;
               int b2 = j*j;

               int c2 = sqrt((a2+b2));

               if(c2 <= n && (c2*c2) == (a2+b2)) cnt++; 
               
            }
        }

        return cnt;
    }
};