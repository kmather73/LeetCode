class Solution {
public:
    int kthGrammar(int N, int K) {        
        vector<int> rep;
        --K;
        --N;
        while(N)
        {
            --N;
            rep.push_back(K%2);
            K /= 2;
        }
        
        int val = 0;
        
        int tbl[2][2] = {
            {0, 1}, 
            {1, 0},
        };
        
        for(int i=rep.size()-1; i >= 0; --i)
        {
            val = tbl[val][rep[i]];
        }
        return val;
    }
};
