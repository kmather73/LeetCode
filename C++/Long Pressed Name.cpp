class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p = 0;
        int q = 0;
        
        while(p < name.size() && q < typed.size())
        {
            if(name[p] == typed[q]) ++p, ++q;
            else if(q > 0 && typed[q] == typed[q-1]) ++q;
            else return false;
        }
        
        return p == name.size();
    }
};
