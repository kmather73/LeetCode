class CBTInserter {
TreeNode* r;
    public:
    CBTInserter(TreeNode* root) : r(root) {
    }
    
    int insert(int v) {
        return Insert(r, v);
    }
    int Insert(TreeNode* t, int val)
    {
        if(t->left == nullptr && t->right == nullptr)
        {
            t->left = new TreeNode(val);
            return t->val;
        }
        else if(t->left != nullptr && t->right == nullptr)
        {
            t->right = new TreeNode(val);
            return t->val;
        }
        else
        {         
            int leftDepth, rightDepth;
            bool hasSpaceInLeftTree = !IsComplete(t->left, leftDepth);
            bool hasSpaceInRightTree = !IsComplete(t->right, rightDepth);
            
            if(hasSpaceInLeftTree || (!hasSpaceInRightTree && leftDepth == rightDepth))
            {
                return Insert(t->left, val);
            }
            else
            {
                return Insert(t->right, val);
            }
        }
    }
    
    TreeNode* get_root() {
        return r;
    }
        
    bool IsComplete(TreeNode* t, int &depth)
    {
        int l = 0;
        int r = 0;
        TreeNode* tt = t;
        while(tt)
        {
            ++l;
            tt = tt->left;
        }
        
        tt = t;
        while(tt)
        {
            ++r;
            tt = tt->right;
        }
        depth = l;
        return l == r;
    }
};
