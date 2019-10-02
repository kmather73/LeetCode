class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> counts;
        for(auto x : arr) ++counts[x];
        
        
        unordered_set<int> unique;
        for(auto p : counts)
        {
            if(unique.count(p.second)) return false;
            else unique.insert(p.second);
        }
        
        return true;
    }
};
