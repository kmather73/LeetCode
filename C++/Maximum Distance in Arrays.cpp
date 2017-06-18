class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        map<int, set<int>> mp;
        for(int i=0; i < arrays.size(); ++i){
            mp[arrays[i][0]].insert(i); 
            mp[arrays[i].back()].insert(i);
        }

        auto it1 = mp.rbegin();
        auto it2 = mp.begin();
        int best = it1->first - it2->first;
        
        if(it1->second.size() > 1 || it2->second.size() > 1 
            || *it1->second.begin() != *it2->second.begin() ) return best;
        
        
        int a = it1->first, b = it2->first;
        ++it1, ++it2;
        int c = it1->first, d =it2->first;
        return max(a-d, c-b);
    }
};
