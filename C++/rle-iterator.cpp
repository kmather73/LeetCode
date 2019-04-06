class RLEIterator {
    int i=0;
    vector<int> rle;
public:
    RLEIterator(vector<int>& A) {
        rle = A;
    }
    
    int next(int n) {
        while(n && i < rle.size())
        {
            if(!rle[i])
            {
                i += 2;
            }
            else
            {
                int d = min(n, rle[i]);
                n -= d;
                rle[i] -= d;
            }
        }
        
        if(i >= rle.size()) return -1;
        return rle[i+1];
    }
};
