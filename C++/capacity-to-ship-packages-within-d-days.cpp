class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        
        auto left = *max_element(weights.begin(), weights.end());
        auto right = 50000 * 500;
        
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            auto ship = ShipmentsWithCapacity(weights, mid);
            if (ship > D) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
    
    int ShipmentsWithCapacity(const vector<int> &w, int c)
    {
        int cap = 0;
        int shipments = 0;
        for(int x : w)
        {
            if(cap >= x) cap -= x;
            else
            {
                ++shipments;
                cap = c - x;
            }
        }
        
        return shipments;
    }
};
