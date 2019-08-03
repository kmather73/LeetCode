class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> colours(N);
        
        unordered_map<int,vector<int>> G;
        for(auto p : paths)
        {
            G[p[0]].push_back(p[1]);
            G[p[1]].push_back(p[0]);
        }
        
        for(auto i = 1; i <= N; ++i)
        {
            vector<bool> used(4);
            for(auto v : G[i])
            {
                if(colours[v-1] != 0) used[colours[v-1] - 1] = true;
            }

            for(int c = used.size(); c > 0; --c)
            {
                if(!used[c-1]) colours[i-1] = c;
            }
        }
        
        return colours;
    }
};
