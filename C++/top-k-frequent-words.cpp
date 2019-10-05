class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> counts;
        for(auto str: words) ++counts[str];
        
        multimap<int, string> inverse;
        for(auto p : counts) inverse.insert(make_pair(-p.second, p.first));
        
        vector<string> ans;
        auto it = inverse.begin();
        for(int i = 0; i < k; ++i) 
        {
            ans.push_back(it->second);
            ++it;
        }
        
        return ans;
    }
};
