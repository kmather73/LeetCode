class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q({0});
        
        while(q.size())
        {
            auto top = q.front(); q.pop();
            if(!visited.count(top))
            {
                visited.insert(top);
                for(auto key : rooms[top]) q.push(key);
            }
        }
        return visited.size() == rooms.size();
    }
};
