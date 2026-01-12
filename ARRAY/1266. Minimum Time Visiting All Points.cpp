class Solution {
public:

    int calculateTime(vector<int>&a, vector<int>&b){

        int x = abs(b[0]-a[0]);
        int y = abs(b[1]-a[1]);

        return (x > y) ? x : y;
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int totalTime = 0;

        for(int i=0; i<points.size()-1; i++){

            int currentTime = calculateTime(points[i], points[i+1]);

            totalTime += currentTime;
        }

        return totalTime;
    }
};