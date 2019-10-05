class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for(auto p : ghosts)
        {
            if(abs(p[0] - target[0]) + abs(p[1] - target[1]) <= dist) return false;
        }
        return true;
    }
};
