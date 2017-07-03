class Solution {
public:
    bool judgeSquareSum(int c) {
        while(c!=0 && c % 4 == 0) c = c / 4;
        if(c%8 == 7) return false;
        
        int limit =  sqrt(c);
        for(int i=0; i <= limit; ++i){
            int a = sqrt(c - i*i);
            if(a*a + i*i == c) return true;
        }
        
        return false;
    }
};
