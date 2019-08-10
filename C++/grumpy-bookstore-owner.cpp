class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int dot = 0;
        int M = 0, G = 0;
        for(int i=0; i < grumpy.size(); ++i)
        {
            dot += (1 - grumpy[i]) * customers[i];
            G += grumpy[i] * customers[i];
            if(i >= X)
            {
                G -= grumpy[i-X] * customers[i-X];
            }
            M = max(M, G);
        }
        
        return dot + M;
    }
};
