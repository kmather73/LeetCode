class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        
        auto i = 1u;
        while(i < N) i *= 2;
        
        return (i-1) & (~N); 
    }
};
