class Solution {
public:
    bool checkRecord(string s) {
        int L = 0, LL = 0;
        int A = 0;
        for(const auto& ch : s) {
            L += (ch == 'L');
            A += (ch == 'A');
            
            if(ch != 'L') L = 0;
            LL = max(LL, L);
        }
        
        return A <= 1 && LL <= 2;
    }
};
