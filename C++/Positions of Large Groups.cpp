class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int i=0; 
        int j=0;
        int n = S.size();
        
        vector<vector<int>> groups;
        
        while(i < n)
        {
            int count = 0;
            while(j < n && S[i] == S[j])
            {
                ++count;
                ++j;
            }
            
            if(count >= 3)
            {
                groups.push_back({i, j-1});
            }
            i = j;
        }
        return groups;
    }
};
