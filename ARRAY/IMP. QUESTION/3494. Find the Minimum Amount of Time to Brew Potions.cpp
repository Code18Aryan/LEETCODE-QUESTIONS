//Ques Link - https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/?envType=daily-question&envId=2025-10-09

class Solution {
public:

    typedef long long ll;

    long long minTime(vector<int>& skill, vector<int>& mana) {
    
        int n = skill.size();
        int m = mana.size();

        vector<long long> time(n,0);

        time[0] = mana[0] * skill[0];

        for(int i=1; i<n; i++){

            time[i] = time[i-1] + (mana[0] * skill[i]);
        }

        for(int i=1; i<m; i++){

            for(int j=0; j<n; j++){

                if(j == 0) time[j] = time[j] + (mana[i] * skill[j]);

                else{

                    time[j] = max(time[j] , time[j-1]) + (mana[i] * skill[j]);
                }
            }

            for(int k=n-1; k>=1; k--){

                time[k-1] = time[k] - (mana[i] * skill[k]);
            }
        }

        return time[n-1];
    }

};
