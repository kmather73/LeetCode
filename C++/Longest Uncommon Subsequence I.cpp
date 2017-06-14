class Solution {
public:
    int findLUSlength(const string &a, const string &b) const {
    if(a.size() != b.size()) return max(a.size(), b.size());
        
        if(a == b) return -1;
        return a.size();
    }
};
