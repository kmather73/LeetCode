class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = INT_MAX;
        
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            int t = 0;
            for(auto p : piles)
            {
                t += p / mid + !!(p%mid);
            }
            
            if(t <= H) right = mid;
            else left = mid+1;
        }
        
        return left;
    }
};
