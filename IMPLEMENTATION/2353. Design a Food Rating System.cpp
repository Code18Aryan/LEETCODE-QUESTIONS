class FoodRatings {
public:

    unordered_map<string,int> foodRating;
    unordered_map<string,string> cuisineName;
    unordered_map<string,set<pair<int,string>>> cuisineFoodRating;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0; i<foods.size(); i++){

            foodRating[foods[i]] = -ratings[i];
            cuisineName[foods[i]] = cuisines[i];
            cuisineFoodRating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        
        int oldRating = foodRating[food];
        string cuisine = cuisineName[food];

        foodRating[food] = -newRating;

        cuisineFoodRating[cuisine].erase({oldRating,food});
        cuisineFoodRating[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        
        // pair<int,string> p = *cuisineFoodRating[cuisine].begin();

        // return p.second;

        // Another way to do

        return begin(cuisineFoodRating[cuisine]) -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */