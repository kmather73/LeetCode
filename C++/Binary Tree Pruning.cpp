class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!HasOne(root)) return nullptr;
        
        return root;
    }
    
    bool HasOne(TreeNode* r)
    {
        if(r == nullptr) return false;
        bool left = HasOne(r->left);
        bool right = HasOne(r->right);
        
        if(r->left && r->left->val==0 && !left) r->left = nullptr;
        if(r->right && r->right->val==0 && !right) r->right = nullptr;
        
        return r->val || left || right;
    }
};
