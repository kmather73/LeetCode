class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int,int>> G;
        for(auto x : times) G[x[0]][x[1]] = x[2];
        
        
        int cost = 0;
        unordered_set<int> used;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push(make_pair(0, K));
        
        while(q.size() && used.size() < N)
        {
            auto next = q.top(); q.pop();
            cost = next.first;
            used.insert(next.second);
            for(auto adj : G[next.second])
            {
                if(!used.count(adj.first))
                {
                    q.push(make_pair(cost + adj.second, adj.first));
                }
            }
        }
        
        return used.size() == N ? cost : -1;
    }
};
