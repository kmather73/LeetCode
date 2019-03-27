class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return PreOrder(preorder, 0, preorder.size());
    }
    
    TreeNode* PreOrder(vector<int> &preorder, int start, int end)
    {
        if(start >= end) return nullptr;
        auto r = new TreeNode(preorder[start]);
        int i = start + 1;
        while(i < end && preorder[i] < preorder[start]) ++i;
        
        r->left = PreOrder(preorder, start+1, i);
        r->right = PreOrder(preorder, i, end);
        
        return r;
    }
};
