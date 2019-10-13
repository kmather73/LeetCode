class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> attack(10, vector<int>(2, -128));
        
        for(auto queen : queens)
        { 
            auto idx = GetAttackIndex(queen, king);
            if(dist(queen, king) < dist(attack[idx], king))
            {
                attack[idx] = queen;
            }
        }
        
        vector<vector<int>> ans;
        for(int i =0 ; i < 9; ++i)
        {
            if(attack[i][0] >= 0) ans.push_back(attack[i]);
        }
        
        return ans;
    }
    
    inline int dist(vector<int> &q, vector<int> &k)
    {
        return abs(q[0] - k[0]) + abs(q[1] - k[1]);
    }
    
    inline int GetAttackIndex(vector<int> &q, vector<int> &k)
    {
        int dx = q[0] - k[0];
        int dy = q[1] - k[1];
        if(dx != 0 && dy != 0 && abs(dx) != abs(dy))
        {
            return 9;
        }
        
        dx = dx ? dx / abs(dx) : dx;
        dy = dy ? dy / abs(dy) : dy;
        
        return (dx + 1) + 3 * dy + 3;
    }
};
