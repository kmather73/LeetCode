class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;
        
        while(label)
        {
            path.push_back(label);
            int row = 1 + log2(label);
            
            if(row % 2)
            {
                label = rev(label/2, row - 1);
            }
            else 
            {
                label = rev(label, row) / 2;
            }
        }
        
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    inline int rev(int x, int row)
    {
        return x == 0 ? 0 : (1<<row) - x + (1<<(row-1)) - 1;
    }
};
