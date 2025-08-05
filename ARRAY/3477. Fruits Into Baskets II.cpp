class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();

        vector<int> canPlace(n,0);

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(baskets[j] >= fruits[i] && !canPlace[j]){

                    canPlace[j] = 1;
                    check = true;
                    break;
                    
                }
            }

        }

        int unPlaced = 0;

        for(auto x : canPlace){

            if(x == 0) unPlaced++;
        }

        return unPlaced;

        // TC- nlogn + o(n) SC - o(n)

        // Better -> Instead of last checking of array is 0 or not. Check after 1st loop we were able to place fruit or not if not increase the unplaced fruit by one
    }
};