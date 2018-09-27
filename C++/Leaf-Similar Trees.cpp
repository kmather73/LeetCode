class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        LeafSequence(root1, tree1);
        LeafSequence(root2, tree2);
        return equal(tree1.begin(), tree1.end(), tree2.begin());
    }
    
    void LeafSequence(TreeNode* r, vector<int> &vals)
    {
        if(!r) return;
        if(!r->left && !r->right) vals.push_back(r->val);
        LeafSequence(r->left, vals);
        LeafSequence(r->right, vals); 
    }
};
