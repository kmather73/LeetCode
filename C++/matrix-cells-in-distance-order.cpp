class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> v;
        for(int i=0; i < R; ++i)
        {
            for(int j=0; j < C; ++j)
            {
                v.push_back({i, j});
            }
        }
        
        sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b)
             {
                 return abs(a[0] - r0) + abs(a[1] - c0) <= abs(b[0] - r0) + abs(b[1] - c0);
             });
        return v;
    }
};
