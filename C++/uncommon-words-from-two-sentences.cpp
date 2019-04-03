class Solution {
public:
    vector<string> uncommonFromSentences(string &A, string &B) {
        unordered_set<string> allA, allB;
        auto uniqueA = GetUniqueStrings(A, allA);
        auto uniqueB = GetUniqueStrings(B, allB);
        
        vector<string> unique;
        
        for(auto a : uniqueA) if(!allB.count(a)) unique.push_back(a);
        
        for(auto b : uniqueB) if(!allA.count(b)) unique.push_back(b);
        
        return unique;
    }
    
    unordered_set<string> GetUniqueStrings(const string &str, unordered_set<string> &allstr)
    {
        unordered_map<string,int> Amap;
        int i=0, j;
        
        while(i < str.size())
        {
            j = str.find(' ', i);
            if(j == string::npos) j = str.size();
            ++Amap[str.substr(i, j-i)];
            
            i = j+1;
        }
        
        unordered_set<string> unique;
        for(auto x : Amap)
        {
            if(x.second == 1) unique.insert(x.first);
            
            allstr.insert(x.first);
        }
        
        return unique;
    }
};
