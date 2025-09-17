#define umap unordered_map
#define uset unordered_set
class FoodRatings {
public:
    umap<string, set<pair<int, string>>> cuisineRating;
    umap<string, int> foodRating;
    umap<string, string> foodCuisines;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodRating.insert({foods[i], ratings[i]});
            foodCuisines.insert({foods[i], cuisines[i]});
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuis = foodCuisines[food];
        int prev = foodRating[food];
        cuisineRating[cuis].erase({-prev, food});
        cuisineRating[cuis].insert({-newRating, food});
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {    
        return cuisineRating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */