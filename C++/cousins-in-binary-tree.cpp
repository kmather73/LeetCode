class Solution {
public:
    bool isCousins(TreeNode* r, int x, int y) {
        unordered_map<int, pair<int,int>> info;
        DFS(r, 0, x, y, info);
        
        return info.count(x) && info.count(y) && info[x].first == info[y].first && info[x].second != info[y].second;
    }
    
    void DFS(TreeNode* r, int level, int x, int y, unordered_map<int, pair<int,int>> &info)
    {
        if(r == nullptr) return;
        
        if(HasValue(r->left, x)) info[x] = make_pair(level, r->val);
        else if(HasValue(r->left, y)) info[y] = make_pair(level, r->val);
        
        if(HasValue(r->right, x)) info[x] = make_pair(level, r->val);
        else if(HasValue(r->right, y)) info[y] = make_pair(level, r->val);
        
        DFS(r->left, level+1, x, y, info);
        DFS(r->right, level+1, x, y, info);
    }
    
    bool HasValue(TreeNode* r, int val)
    {
        return r && r->val == val;
    }
};
