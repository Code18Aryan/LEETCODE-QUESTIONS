class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int finalValue = 0;

        for(int i=0; i<operations.size(); i++){

            if(operations[i][0] == '-' || operations[i][2] == '-') finalValue--;
            else finalValue++;
        }

        return finalValue;
    }
};