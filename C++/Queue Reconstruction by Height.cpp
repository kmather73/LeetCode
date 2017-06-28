class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
       
        map<int, vector<int>> mp;
        set<int> unusedPos;
        int n = people.size();
        for(int i=0; i<n; ++i) {
            const auto &x = people[i];
            mp[x.first].push_back(x.second);
            unusedPos.insert(i);
        }
        
        vector<pair<int,int>> queue(n);
        for(auto &x : mp){
            sort(x.second.rbegin(), x.second.rend());
            for(auto &y: x.second) {
                auto it = unusedPos.begin();
                for(int i=0; i<y; ++i) ++it;
                queue[*it] = make_pair(x.first, y);
                unusedPos.erase(it);
            }
        }
        
        return queue;
    }
};
