class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* r, int val) {
        if(r == nullptr || r->val < val)
        {
            auto newR = new TreeNode(val);
            newR->left = r;
            return newR;
        } 
        
        r->right = insertIntoMaxTree(r->right, val);
        return r;
    }
};
