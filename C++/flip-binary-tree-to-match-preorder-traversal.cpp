class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        unordered_map<int,int> idx;
        
        for(int i=0; i < voyage.size(); ++i) idx[voyage[i]] = i;
        
        vector<int> flips;
        
        if(DFS(root, 0, voyage.size(), voyage, idx, flips)) return flips;
        
        return vector<int>(1, -1);
    }
    
    bool DFS(TreeNode* r, int start, int end, vector<int> &voyage, unordered_map<int,int> &idx, vector<int> &flips)
    {
        if(r == nullptr) return start >= end;
        
        if(r->val != voyage[start]) return false;
        bool canSolve = true;
        
        auto rightIndex = r->right ? idx[r->right->val] : end;
        auto leftIndex = r->left ? idx[r->left->val] : end;
        if(leftIndex == start + 1)
        {
            canSolve = canSolve && DFS(r->left, leftIndex, rightIndex, voyage, idx, flips);
            canSolve = canSolve && DFS(r->right, rightIndex, end, voyage, idx, flips);
        }
        else if(rightIndex == start + 1)
        {
            if (leftIndex != end) flips.push_back(r->val);
            canSolve = canSolve && DFS(r->right, rightIndex, leftIndex, voyage, idx, flips);
            canSolve = canSolve && DFS(r->left, leftIndex, end, voyage, idx, flips);
        }
        else canSolve = false;
        
        return canSolve;
    }
};
