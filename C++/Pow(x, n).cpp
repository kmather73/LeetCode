class Solution {
public:
    double myPow(double x, int n) {
       if(n == 0) 
            return 1;
       double nBy2 = n/2;
       double power = n > 0 ? myPow(x, nBy2) : myPow(x = 1/x , -nBy2 );
       return    power * power * ( n - 2*nBy2 ? x : 1);
    }
};
