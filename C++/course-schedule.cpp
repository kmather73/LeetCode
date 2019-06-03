class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> G;
        
        for(auto c : prerequisites) G[c[0]].push_back(c[1]);
        
        vector<bool> haveTaken(numCourses);
        vector<bool> visited(numCourses);
        bool canTakeAll = true;
        for(int i=0; i < numCourses; ++i)
        {
            canTakeAll = canTakeAll && DFS(i, G, haveTaken, visited);
        }
        
        return canTakeAll;
    }
    
    bool DFS(int i, unordered_map<int, vector<int>> &G, vector<bool> &taken, vector<bool> &visited)
    {
        if(taken[i] || visited[i]) return taken[i];
        
        bool canTake = true;
        visited[i] = true;
        for(auto c : G[i])
        {
            canTake = canTake && DFS(c, G, taken, visited);
        }
        
        visited[i] = false;
        return taken[i] = canTake;
    }
       
};
