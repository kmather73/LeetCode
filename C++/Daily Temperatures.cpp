class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> days(T.size());
        priority_queue<pair<int,int>> q;
        
        for(int i=0; i < T.size(); ++i)
        {
            while(q.size() && q.top().first > -T[i])
            {
                auto top = q.top(); q.pop();
                days[top.second] = i - top.second;
            }
            q.push(make_pair(-T[i], i));
        }
        return days;
    }
};
