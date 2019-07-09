class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 0;
        int c = 1;
        vector<int> distribution(num_people);
        
        while(candies)
        {
            auto delta = min(c++, candies);
            distribution[i] += delta;
            candies -= delta;
            i = (i + 1) % num_people;
        }
        
        return distribution;
    }
};
