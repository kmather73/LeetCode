class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int r = 0;
        sort(heaters.begin(), heaters.end());
        for(auto h : houses)
        {
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            
            int d = INT_MAX;
            if(it != heaters.end())
            {
                d = *it - h;
            }
            
            if(it != heaters.begin())
            {
                --it;
                d = min(d, h - *it);
            }
            
            r = max(r, d);
        }
        
        return r;
    }
};
