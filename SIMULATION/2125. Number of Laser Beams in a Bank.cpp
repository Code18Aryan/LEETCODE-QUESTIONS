class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        int prevDevice = 0;
        int totalBeam = 0;

        for(int i=0; i<n; i++){

            int currentDevice = 0;
            bool hasDevice = false;

            for(int j=0; j<bank[i].size(); j++){

                if(bank[i][j] == '1'){

                    hasDevice = true;
                    currentDevice += 1;
                }
            }
            
            totalBeam += (currentDevice * prevDevice);

            if(hasDevice){

                prevDevice = currentDevice;
            }
        }

        return totalBeam;

    }
};