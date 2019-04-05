class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> nodes;
        unordered_map<TreeNode*, TreeNode*> parents;
        int maxDepth = -1;
        DFS(root, 0, maxDepth, parents, nodes);
                
        int j=1, n = nodes.size();
        while(j < n)
        { 
            while(j < n && parents[nodes[j-1]] == parents[nodes[j]]) ++j;
            
            for(int i=j-1; i < n; ++i)
            {
                nodes[i] = parents[nodes[i]]; 
            }
        }
        
        return nodes.back();
    }
    
    void DFS(TreeNode* r, int depth, int& maxDepth, unordered_map<TreeNode*, TreeNode*> &parents, vector<TreeNode*> &nodes)
    {
        if(depth > maxDepth) nodes.clear();
        maxDepth = max(maxDepth, depth);
        if(r->left)
        {
            DFS(r->left, depth + 1, maxDepth, parents, nodes);
            parents[r->left] = r;
        }
        
        if(r->right)
        {
            DFS(r->right, depth + 1, maxDepth, parents, nodes);
            parents[r->right] = r;
        }
        
        if(maxDepth == depth)
        {
            nodes.push_back(r);
        }
    }
};
