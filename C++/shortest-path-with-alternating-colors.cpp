using Graph = unordered_map<int,unordered_map<int, int>>;
using DP = vector<unordered_map<size_t, int>>;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> paths(n, -1);
        paths[0] = 0;
        
        DP dp(n);
        
        Graph GR;
        Graph GB;
        for(auto er : red_edges) GR[er[0]][er[1]] = 1;
        for(auto eb : blue_edges) GB[eb[0]][eb[1]] = 1;
        
        DFS(0, 1, paths, GR, GB, dp);
        DFS(0, 1, paths, GB, GR, dp);
        
        return paths;
    }
    
    void DFS(int node, int depth, vector<int> &paths, Graph &G1, Graph &G2, DP &dp)
    {
        auto key = reinterpret_cast<size_t>(&G1);
        if(dp[node].count(key) && dp[node][key] < depth) return;
        dp[node][key] = depth;
        for(auto &e : G1[node])
        {
            if(e.second)
            {
                e.second = 0;
                paths[e.first] = paths[e.first] > -1 ? min(paths[e.first], depth) : depth;
                DFS(e.first, depth + 1, paths, G2, G1, dp);
                e.second = 1;
            }
        }
    }
};
