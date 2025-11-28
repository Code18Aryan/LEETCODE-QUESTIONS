class Solution {
public:


    int requiredDays(vector<int>& weights, int capacity){
        
        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++){

            if( load + weights[i] <= capacity){

                load+=weights[i];
            }

            else{
                   days++;
                   load=weights[i];
            }
        }

        return days;
    }
 


    int shipWithinDays(vector<int>& weights, int days) {

        int n=weights.size();

       // int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum = 0;

        for(int i=0; i<n; i++){ 

           // mini=min(mini , weight[i]); 

            maxi=max(maxi , weights[i]);
            sum+=weights[i];

        }

        int low=maxi;  int high=sum;

        while(low <= high){

              int mid = (low+high)/2;
              int daysTaken=requiredDays(weights,mid);

              if(daysTaken <= days)  high=mid-1;

              else  low=mid+1;
        }
        
          return low;
    }
};