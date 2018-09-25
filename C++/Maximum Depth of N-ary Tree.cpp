class Solution {
public:
    int maxDepth(Node* root) {        
        int depth = 0;
        maxDepth(root, 0, depth);
        return depth;
    }
    
    void maxDepth(Node* r, int depth, int &maimumxDepth)
    {
        if(!r) return;
        maimumxDepth = max(maimumxDepth, depth+1);
        for(auto node : r->children) maxDepth(node, depth + 1, maimumxDepth);
    }
};
