class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int n = s1.size();

        if(s1 == s2) return true; 

        int start = -1;
        int end = -1;

        for(int i=0; i<n; i++){

            if(s1[i] != s2[i]){

                if(start == -1){

                    start = i;
                }

                end = i;
            }
        }

        swap(s1[start],s1[end]);

        return s1 == s2;
        
    }
};