class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> counts;
        for(auto x : deck) ++counts[x];
        
        if(counts.size() < 2) return deck.size() > 1;
        
        
        int gcd = counts[deck[0]];
        for(auto x : counts) gcd = __gcd(x.second, gcd);
        
        
        return gcd != 1;
    }
};
