class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        auto r = root;
        while(r != nullptr)
        {
            if(r->val < val)
            {
                if(r->right == nullptr) 
                {
                    r->right = new TreeNode(val);
                    break;
                }
                else r = r->right;
            }
            else
            {
                if(r->left == nullptr) 
                {
                    r->left = new TreeNode(val);
                    break;
                }
                else r = r->left;
            }
        }
        return root;
    }
};
