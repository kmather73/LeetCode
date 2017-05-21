class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1 = distSqr(p1, p2);
        int d2 = distSqr(p1, p3);
        int d3 = distSqr(p1, p4);
        if(d1 == 0 || d2 == 0 || d3 == 0) return false;
        vector<int> v12 {p2[0]-p1[0], p2[1]-p1[1]};
        vector<int> v13 {p3[0]-p1[0], p3[1]-p1[1]};
        vector<int> v14 {p4[0]-p1[0], p4[1]-p1[1]};
        
        if(d1 == d2 + d3){
            return d2 == d3 && utill(p4, v13, p2);
        } else if(d2 == d1+d3){
            return d1 == d3 && utill(p2, v14, p3);
        } else if(d3 == d1 + d2){
            return d1 == d2 && utill(p2, v13, p4);
        }
        
        return false;
    }
    bool utill(vector<int>& src, vector<int>& v, vector<int>& trg){
        return src[0]+v[0] == trg[0] && src[1]+v[1] == trg[1];
        
    }
    int distSqr(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0]) * (p1[0]-p2[0]) 
                + (p1[1]-p2[1]) * (p1[1]-p2[1]);
    }
};
