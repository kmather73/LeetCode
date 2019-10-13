class Solution {
public:
    int balancedStringSplit(string s) {
        int L = 0, R = 0;
        for(auto ch : s)
        {
            L += ch == 'L';
            R += ch == 'R';
        }
        
        if(L != R) return 0;
        
        int count = 0;
        for(auto ch : s)
        {
            L -= ch == 'L';
            R -= ch == 'R';
            
            if(L == R) ++count;
        }
        
        return count;
    }
};
