class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(const auto& ch : s) ++mp[ch];
        
        vector<pair<int,int>> order;
        for(auto& x: mp) order.push_back(x);
        
        auto cmp =[](pair<int, int> &a, pair<int, int> &b) {
          return a.second > b.second;
        };
        sort(order.begin(), order.end(), cmp);
        
        string str = "";
        for(auto x : order){
            for(int i=0; i<x.second; ++i){
                str += x.first;
            }
        }
        
        return str;
    }
};
