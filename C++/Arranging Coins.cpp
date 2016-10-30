class Solution {
public:
    int arrangeCoins(int n) {
        long long int i=1;
        while( i*(i+1)/2 <= n) ++i;
        
        return i-1;
    }
};
