class Solution {
public:
    int distSqrd(pair<int,int> &a, pair<int,int> &b){
        int d1 = a.first - b.first;
        int d2 = a.second - b.second;
        return d1*d1 + d2*d2;
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int count = 0;
        
        for(int i=0 ; i < n; ++i){
            unordered_map<int, vector<int>> map = unordered_map<int, vector<int>>();
            for(int j = 0; j < n; ++j){
                int dist = distSqrd(points[i], points[j]);
                map[dist].push_back(j);
            }
            
            for(const auto &p : map){
                int x = p.second.size();
                count += x * (x-1);
            }
        }
        return count;
    }
};
