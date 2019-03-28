class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> UF(26);
        for(int i=0; i < UF.size(); ++i) UF[i] = i;
        
        sort(equations.begin(), equations.end(), 
             [](const string &a, const string &b)
             {
               return a[1] > b[1];  
             });
        
        int i=0;
        while(i < equations.size() && equations[i][1] == '=') 
        {
            Union(UF, equations[i][0]-'a', equations[i][3]-'a');
            ++i;
        }
        
        while(i < equations.size())
        {
            auto a = Find(UF, equations[i][0]-'a');
            auto b = Find(UF, equations[i][3]-'a');
            if(a == b) return false;
            
            ++i;
        }
        
        return true;
    }
    
    void Union(vector<int> &UF, int i, int j)
    {
        auto fi = Find(UF, i);
        auto fj = Find(UF, j);
        
        UF[fi] = fj;
    }
    
    int Find(vector<int> &UF, int i)
    {
        while(UF[i] != UF[UF[i]]) UF[i] = UF[UF[i]];
        
        return UF[i];
    }
};
