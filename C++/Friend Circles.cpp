class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        for(int i=0; i < M.size(); ++i){
            count += findCC(M, i);
        }
        
        return count;
    }
    
    int findCC(vector<vector<int>>& M, int s){
        if(M[s][s] == 0) return 0;
        
        M[s][s] = 0;
        
        for(int i=0; i < M.size(); ++i){
            if(M[i][s] == 1) {
                M[i][s] = M[s][i] = 0;
                findCC(M, i);
            }
        }
        
        return 1;
    }
};
