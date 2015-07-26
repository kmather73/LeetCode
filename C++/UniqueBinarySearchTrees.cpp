class Solution {
public:
    int numTrees(int n) {
        
        vector<int> myNumTrees(n + 1, 0)
        myNumTrees[0] = 1;
        myNumTrees[1] = 1;
        
        for(int i = 1; i <=n; ++i){
            int sum = 0;
            for(int j = 0; j < i; ++j)
                sum += myNumTrees[j]*myNumTrees[i-j-1];
            myNumTrees[i] = sum;
        }
        return myNumTrees[n];
    }
};
