//Ques Link - https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

class Solution {
public:
    int totalMoney(int n) {
        
        int totalWeeks = n/7;
        int remainingDays = n%7;
        int totalMoney = 0;
        int monday = 1;
        int sunday = 7;

        while(totalWeeks--){

            for(int i=monday; i<=sunday; i++){

                totalMoney += i;
            }

            monday++;
            sunday++;
        }

        while(remainingDays--){

            totalMoney += monday;
            monday++;
        }

        return totalMoney;
    }

};
