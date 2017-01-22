class Solution {
public:
    vector<int> constructRectangle(int area) {
        int n = (int) sqrt(area);
        int j = 0;
        for(int i=1; i <= n; ++i){
            if(i*(area/i) == area) j = i;
        }
        vector<int> v{area/j,j};
        
        return v;
    }
};
