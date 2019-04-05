class Solution {
public:
    int clumsy(int N) {
        vector<int> sums;
        vector<function<int(int,int)>> ops = {plus<int>(), minus<int>()}; // multiplies<int>(), divides<int>(), 
        
        while(N > 0)
        {
            sums.push_back(MultDiv(N));
            N -= 3;
            
            if(N > 0) sums.push_back(N--);
        }
        
        for(int i=1; i < sums.size(); ++i)
        {
            sums[0] = ops[(1+i)%2](sums[0], sums[i]);
        }
        
        return sums[0];
    }
    
    inline int MultDiv(int n)
    {
        if(n <= 2) return n;
        return n * (n-1) / (n-2);
    }
};
