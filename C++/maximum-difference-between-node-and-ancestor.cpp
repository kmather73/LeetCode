class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        set<int> ancestors;
        int maxDif = 0;
        DFS(root, ancestors, maxDif);
        return maxDif;
    }
    
    void DFS(TreeNode* r, set<int> &ancestors, int &maxDif)
    {
        if(r != nullptr)
        {
            ancestors.insert(r->val);
            maxDif = max(maxDif, (*ancestors.rbegin()) - (*ancestors.begin()));
            DFS(r->left, ancestors, maxDif);
            DFS(r->right, ancestors, maxDif);
            ancestors.erase(r->val);
        }
    }
};
