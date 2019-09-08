class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int s, int d) {
        int n = distance.size();
        int distR = 0;
        int distL = 0;
        
        if(s > d) swap(s, d);
        
        for(int i = 0; i < n; ++i)
        {
            if(i < s || i >= d) distL += distance[i];
            else distR += distance[i];
        }
        
        return min(distL, distR);
    }
};
