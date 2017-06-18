class Solution {
public:
    int smallestFactorization(int a) {
        if(a == 1) return 1;
       
        
        int d = 9;
        vector<int> x;
        while( a > 1){
            if(d <= 1) return 0;
            while( a%d == 0){
                a /= d;
                x.push_back(d);
            }
            
            --d;
        }
        
        int long y = 0;
        while(x.size()){
            y = 10*y + x.back();
            x.pop_back();
        }
        
        int z = (int) y;
        
        if(z == y) return z;
        return 0;
        
    }
};
