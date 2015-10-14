class Solution {
public:
    int numTrees(int n) {
        
        vector<int> numOfTrees(n + 1, 0)
        numOfTrees[0] = 1;
        numOfTrees[1] = 1;
        
        for(int i = 1; i <=n; ++i){
            int sum = 0;
            for(int j = 0; j < i; ++j)
                sum += numOfTrees[j] * numOfTrees[i-j-1];
            numOfTrees[i] = sum;
        }
        return numOfTrees[n];
    }
};
