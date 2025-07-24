class Solution {
public:
    int maxProfit(vector<int>& prices) {

       // FOR SELLING A STOCK, IF WANT TO MAKE PROFIT THEN SELLING 
       //PRICE MUST BE GREATER THAN COST PRICE(BUYING PRICE) AND FOR
       // ith SELLING STOCK YOU WANT MINIMUM TO THE LEFT, SO FOR ith 
       //STOCK WE WANT MINIMUM NUMBER TO THE LEFT
       
       
       int n = prices.size();
       int maxProfit = 0;
       
       int mini = prices[0];
       
       for(int i=1; i<n; i++){
           
           if(prices[i] > mini){
               
               int profit = prices[i] - mini;
               
               maxProfit = max(maxProfit,profit);
           }
           
           mini = min(mini,prices[i]);
           
       }
       
       return maxProfit;
    

        
    }
};