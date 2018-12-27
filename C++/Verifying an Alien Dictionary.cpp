class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i=0; i < order.size(); ++i) map[order[i]] = i;
        
        for(int i=1; i<words.size(); ++i)
        {
            if(!Less(words[i-1], words[i], map)) return false;
        }
        
        return true;
    }
    
    bool Less(string& a, string& b, unordered_map<char, int>& map)
    {
        int i=0;
        int n = a.size(), m = b.size();
        
        while(i < n && i < m)
        {
            if(map[a[i]] < map[b[i]]) return true;
            else if(map[a[i]] > map[b[i]]) return false;
            ++i;
        }
        
        return i == n;
    }
};
