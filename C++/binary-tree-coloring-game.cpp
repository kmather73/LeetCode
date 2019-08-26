enum GraphComp
{
    Parent,
    Left,
    Right,
};

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> v(3);
        DFS(root, v, Parent, x);
        
        return max(v[0], max(v[1], v[2])) > n / 2;
    }
    
    void DFS(TreeNode* r, vector<int> &sums, GraphComp kind, int x)
    {
        if(r == nullptr) return;
        
        if(r->val == x)
        {
            DFS(r->left, sums, Left, x);
            DFS(r->right, sums, Right, x);
        }
        else
        {
            ++sums[kind];
            DFS(r->left, sums, kind, x);
            DFS(r->right, sums, kind, x);
        }
    }
};
