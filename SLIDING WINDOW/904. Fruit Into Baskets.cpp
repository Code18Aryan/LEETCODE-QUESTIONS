class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // BINARY SEARCH OR SLIDING WINDOW
        unordered_map<int,int> mpp;
        int i=0, j=0, maxiFruit = 0;
        int n = fruits.size();

        while( j < n){

            mpp[fruits[j]]++;

            while(mpp.size() > 2){

                mpp[fruits[i]]--;
                
                if(mpp[fruits[i]] == 0){

                    mpp.erase(fruits[i]);
                }

                i++;
            }

            maxiFruit = max(maxiFruit,j-i+1);
            j++;
        }

        return maxiFruit;
    }

};
