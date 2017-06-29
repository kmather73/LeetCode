class Solution {
public:
    int lastRemaining(int n) {
        return utill(n, true);
    }
    
    int utill(int n, bool left){
        if(n == 1) return 1;
        
        if(left) return 2*utill(n/2, false);
        return  2*utill(n/2, true) - ((1+n)%2);
    }
};
