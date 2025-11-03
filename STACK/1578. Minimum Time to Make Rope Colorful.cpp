class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        stack<pair<char,int>> st;
        st.push({colors[0],0});

        // Just check if the previous balloons have same color or not, if yes the take minTime of it and remove the min one from stack
        // or if the previous time is min dont push the current time and color
        // of the color is not same then push new color with index
        

        int minTime = 0;

        for(int i=1; i<colors.size(); i++){

            if(!st.empty() && st.top().first == colors[i]){

                if(neededTime[st.top().second] <= neededTime[i]){

                    minTime += neededTime[st.top().second];
                    st.pop();
                    st.push({colors[i],i});
                }

                else{

                    minTime += neededTime[i];
                    
                }
            }

            else st.push({colors[i],i});
        }

        return minTime;
    }
};
