class Solution {
    vector<int> Fac {1, 1, 2, 6, 24, 120, 720, 5040};
public:
    int numTilePossibilities(string &tiles) {
        sort(tiles.begin(), tiles.end());
        int sum = 0;
        vector<int> letters(26, 0);
        string s = "";
        unordered_set<string> dp;
        DFS(dp, 0, tiles, s, sum, letters);
        return sum;
    }
    
    void DFS(unordered_set<string> &dp, int i, string& tiles, string& s, int &sum, vector<int> &v)
    {
        if(i >= tiles.size()) return;
        
        auto ch = tiles[i] - 'A';
        s.push_back(ch);
        if(!dp.count(s))
        {
            dp.insert(s);            
            ++v[ch];
            sum += Multinom(v);
            DFS(dp, i+1, tiles, s, sum, v);
            --v[ch];
        }
        s.pop_back();
        
        DFS(dp, i+1, tiles, s, sum, v);    
    }
    
    int Multinom(vector<int> v)
    {
        int dom = 1, num = 0;
        
        for(auto y : v) 
        {
            dom *= Fac[y];
            num += y;
        }
        
        return Fac[num] / dom;
    }
};
