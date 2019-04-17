class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto plateDist = WordDist(licensePlate);

        string m = "";
        for(auto word : words)
        {
            auto dist = WordDist(word);
            if(IsSubDist(dist, plateDist))
            {
                if(!m.size() || word.size() < m.size()) m = word;
            }
        }
        
        return m;
    }
    
    unordered_map<char, int> WordDist(const string &w)
    {
        unordered_map<char, int> dist;
        for(char ch: w)
        {
            if(isalpha(ch)) ++dist[tolower(ch)];
        }
        
        return dist;
    }
    
    bool IsSubDist(unordered_map<char, int> a, unordered_map<char, int> b)
    {
        for(auto p : a) b[p.first] -= p.second;
        
        for(auto p : b) if(p.second > 0) return false;
        
        return true;
    }
};
