class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), 
            [](const vector<int> &a, const vector<int> &b)
             {
                if(a[1] == b[1]) return a[2] <= b[2];
                return a[1] <= b[1];
             });
        
        auto cmp = [&](const int a, const int b)
        {
            return trips[a][2] > trips[b][2];
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for(int i = 0; i < trips.size(); ++i)
        {
            while(q.size() && trips[q.top()][2] <= trips[i][1])
            {
                capacity += trips[q.top()][0];
                q.pop();
            }
            
            capacity -= trips[i][0];
            if(capacity < 0) return false;
            q.push(i);
        }
        
        return true;
    }
};
