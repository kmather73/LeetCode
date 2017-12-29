class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) flood(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void flood(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != oldColor) return;
        
        image[r][c] = newColor;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int i=0; i < 4; ++i) flood(image, r+dx[i], c+dy[i], oldColor, newColor);
    }
};
