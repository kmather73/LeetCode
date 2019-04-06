class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> &tickets) {
        unordered_map<string, map<string, int>> flights;
        for(auto p : tickets)
        {
            ++flights[p.first][p.second];
        }       
        
        int limit = tickets.size() + 1;
        vector<string> path{"JFK"}, maxPath;
        DFS(flights, path, maxPath, limit);
        return maxPath;
    }
    
    void DFS(unordered_map<string, map<string, int>> &G, vector<string> &path, vector<string> &maxPath, int limit)
    {
        if(maxPath.size() == limit) return;
        if(path.size() == limit)
        {
            maxPath = path;
            return;
        }
        
        for(auto port : G[path.back()])
        {
            if(port.second)
            {
                --G[path.back()][port.first];
                path.push_back(port.first);
                DFS(G, path, maxPath, limit);
                path.pop_back();
                ++G[path.back()][port.first];
            }
        }
    }
};
