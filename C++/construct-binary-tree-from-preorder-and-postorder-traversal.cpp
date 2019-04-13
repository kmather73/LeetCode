class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return ConstructTree(pre, post, 0, pre.size()-1, 0, post.size()-1);
    }
    
    TreeNode* ConstructTree(vector<int>& pre, vector<int>& post, int preS, int preE, int postS, int postE)
    {
        if(preS > preE) return nullptr;
        if(preS == preE) return new TreeNode(pre[preS]);
        
        auto t = new TreeNode(pre[preS]);
        int L = FindPostOrderLeft(post, postS, postE - 1, pre[preS+1]) - postS + 1;
        
        t->left = ConstructTree(pre, post, preS+1, preS+L, postS, postS+L+1);
        t->right = ConstructTree(pre, post, preS+L+1, preE, postS+L, postE-1);
        
        return t;
    }
    
    inline int FindPostOrderLeft(vector<int> &post, int s, int e, int v)
    {
        while(s <= e && post[s] != v) ++s;
        return s;
    }
};
