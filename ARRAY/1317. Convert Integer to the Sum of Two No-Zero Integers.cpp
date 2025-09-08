class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1; i<n; i++){

            string first = to_string(i);    
            string second = to_string(n-i);

            if((first).find('0') != -1 || (second).find('0') != -1){

                continue;
            }

            return {i,n-i};
        }

        return {};
    }
};