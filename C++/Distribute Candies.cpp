class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int> set;
        
        for(int& x: candies)
            set[x] = 1;
        
        return set.size()*2 >= candies.size()? candies.size()/2 : set.size() ;
    }
};
