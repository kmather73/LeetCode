class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deleteMe;
        for(auto x : to_delete) deleteMe.insert(x);
        vector<TreeNode*> trees;
        
        DFS(root, deleteMe, trees, true);
        
        return trees;
    }
    
    void DFS(TreeNode* r, unordered_set<int> &deleteMe, vector<TreeNode*> &trees, bool addMe)
    {
        if(r == nullptr) return;
        
        auto addToTrees = deleteMe.count(r->val);
        if(addMe && !addToTrees) trees.push_back(r);
        
        DFS(r->left, deleteMe, trees, addToTrees);
        DFS(r->right, deleteMe, trees, addToTrees);
        
        if(r->left && deleteMe.count(r->left->val)) r->left = nullptr;
        if(r->right && deleteMe.count(r->right->val)) r->right = nullptr;
    }
};
