class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left=0, right=0;
        unordered_map<int,unordered_map<int, vector<int>>> values;
        unordered_map<int, set<int>> coord;
        DFS(root, 0, 0, left, right, values, coord);
        vector<vector<int>> order(right-left+1);
        for(int i=left; i <= right; ++i)
        {
            for(auto j : coord[i])
            {
                sort(values[i][j].begin(), values[i][j].end());
                for(auto x : values[i][j]) order[i-left].push_back(x);
            }
        }
        
        return order;
    }
    
    void DFS(TreeNode* r, int level, int pos, int &left, int &right, 
             unordered_map<int,unordered_map<int, vector<int>>> &values,
             unordered_map<int, set<int>> &coord)
    {
        if(r == nullptr) return;
        
        coord[pos].insert(level);
        values[pos][level].push_back(r->val);
        left = min(left, pos);
        right = max(right, pos);
        
        DFS(r->left, level+1, pos-1, left, right, values, coord);
        DFS(r->right, level+1, pos+1, left, right, values, coord);
    }
};
