class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, unordered_map<int,int>> G;
        unordered_map<int,int> GG;
        for(auto p : trust)
        {
            G[p[1]][p[0]] = 1;
            ++GG[p[0]];
        }
        
        for(int i=1; i <= N; ++i)
        {
            bool trustFree = GG[i] == 0;
            bool everyonesTrust = G[i].size()+1 == N;
            if(trustFree && everyonesTrust) return i;
        }
        
        return -1;
    }
};
