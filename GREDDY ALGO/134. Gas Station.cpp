class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        
        int totalGas = 0;
        int totalCost = 0;
        int ansIndex = 0;
        int fuel = 0;
        
        for(int i=0; i<gas.size(); i++){
            
            totalGas += gas[i];
            totalCost += cost[i];
            
            int currentFuel = gas[i] - cost[i];
            
            fuel += currentFuel;
            
            if(fuel < 0){
                
                ansIndex = i+1;
                fuel = 0;
            }
        }
        
        if(totalGas < totalCost) return -1;
        
        return ansIndex;
        
    }
};