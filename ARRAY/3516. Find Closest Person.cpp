#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {

        int distanceFromXtoZ = abs(x-z);
        int distanceFromYtoZ = abs(y-z);

        if(distanceFromXtoZ < distanceFromYtoZ) return 1;
        if(distanceFromXtoZ > distanceFromYtoZ) return 2;

        return 0;
    }
};