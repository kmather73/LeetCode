class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long dawinding = winding(points[n-1], points[0], points[1]);
        
        for(int i=0; i < points.size(); ++i){
            if( dawinding*winding(points[i%n], points[(i+1)%n], points[(i+2)%n]) < 0) return false;
        }
        
        return true;
    }
    
    long winding(vector<int> p, vector<int> q, vector<int> r){
        return (q[0]-p[0])*(r[1]-q[1]) - (q[1]-p[1])*(r[0]-q[0]);
    }
};
