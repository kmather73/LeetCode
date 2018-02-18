class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int> color;
        
        bool isBipartite = true;
        for(int i=0; i < graph.size(); ++i){
            if(color.count(i) == 0) color[i] = 0;
            
            for(auto x : graph[i]){
                if(color.count(x) && color[x] == color[i]) return false;    
                else color[x] = !color[i];
            }
        }
        return true;
    }
};
