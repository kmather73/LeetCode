class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        auto maxArea = 0.0;
        for(int i=0; i < n; ++i)
        {
            for(int j=i+1; j < n; ++j)
            {
                for(int k = j+1; k < n; ++k)
                {
                    double area = (points[i][0] - points[j][0]) * (points[k][1] - points[j][1])
                        -(points[i][1] - points[j][1]) * (points[k][0] - points[j][0]);
                    
                    area = area / 2.0;
                    if(area < 0) area = -area;
                    
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};
