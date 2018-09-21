class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        Inorder(root, s);
        
        while(s.size())
        {
            root = s.top(); s.pop();
            if(s.size()) s.top()->right = root;
        }
        return root;
    }
    
    void Inorder(TreeNode* r, stack<TreeNode*> &s)
    {
        if(r == nullptr) return;
        Inorder(r->left, s);
        s.push(r);
        Inorder(r->right, s);
        r->right = nullptr;
        r->left = nullptr;
    }
};
