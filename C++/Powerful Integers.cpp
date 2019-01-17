class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(min(1, x) + min(1, y) > bound) return {};
        unordered_set<int> unums;
        int xx = 1;
        if(x < y) swap(x, y);
        do
        {
            int yy = 1;
            do
            {
                unums.insert(xx + yy);
                yy *= y;
            } while(xx + yy <= bound && y > 1);
            xx *= x;
        } while(xx + 1 <= bound && x > 1);
        
        vector<int> nums;
        for(auto x : unums) nums.push_back(x);
        
        return nums;
    }
};
