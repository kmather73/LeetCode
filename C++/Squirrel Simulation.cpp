class Solution {
public:
    long minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        if(nuts.size() == 0) return 0;
        
        long nutDist = 0;
        int minDist = INT_MAX;
        
        for(const auto& nut : nuts){
            int si = dist(squirrel, nut);
            int td = dist(tree, nut);
            
            nutDist += 2*td;
            minDist = min(minDist, si-td);
        }
        
        return nutDist + minDist;
    }
    
    int dist(const vector<int>& a, const vector<int>& b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
};
