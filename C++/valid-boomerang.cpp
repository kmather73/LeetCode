class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto dx = points[0][0] - points[1][0];
        auto dy = points[0][1] - points[1][1];
        
        return dx * (points[0][1] - points[2][1]) != dy * (points[0][0] - points[2][0]);
    }
};
