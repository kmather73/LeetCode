class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        auto lastLeft = 0;
        int n = seats.size();
        
        while(lastLeft < n && !seats[lastLeft]) ++lastLeft;
        
        auto dist = lastLeft;
        
        for(int i=lastLeft+1; i < n; ++i)
        {
            if(seats[i] == 1)
            {
                auto tmp = (i - lastLeft) / 2;
                dist = max(dist, tmp);
                lastLeft = i;
            }
        }
        
        if(seats[n-1] == 0) dist = max(dist, (n-1 - lastLeft));
        return dist;
    }
};
