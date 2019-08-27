class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path{0};
        DFS(graph, path, paths);
        return paths;
    }
    
    void DFS(vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> &paths)
    {
        if (path.rbegin()[0] + 1 == graph.size()) 
        {
            paths.push_back(path);
            return;
        }
        
        for (auto i : graph[path.rbegin()[0]])
        {
            path.push_back(i);
            DFS(graph, path, paths);
            path.pop_back();
        }
    }
};
