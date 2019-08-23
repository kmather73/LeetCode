using Index = unordered_map<char, int>;
class Solution {
public:
    int countCharacters(vector<string>& words, string &chars) {
        Index goodChars = IndexString(chars);
        int length = 0;
        for(auto str : words)
        {
            auto wordIdx = IndexString(str);
            if(SubsetIndex(goodChars, wordIdx))
            {
                length += str.size();
            }
        }
        
        return length;
    }
    
    Index IndexString(string &s)
    {
        Index idx;
        for(auto ch : s) ++idx[ch];
        
        return idx;
    }
    
    bool SubsetIndex(Index &i, Index &j)
    {
        for(auto pair : j)
        {
            if(!i.count(pair.first) || i[pair.first] < pair.second)
            {
                return false;
            }
        }
        
        return true;
    }
};
