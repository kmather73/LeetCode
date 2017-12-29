/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int len = 0;
        DFS(root, len);
        return len;
    }
    
    int DFS(TreeNode* r, int &x) {
        if(r == nullptr) return 0;
        
        int left = DFS(r->left, x);
        int right = DFS(r->right, x);
        int recLeft  = r->left && r->left->val == r->val ? 1+left: 0;
        int recRight  = r->right && r->right->val == r->val ? 1+right: 0;
        
        x = max(x, recLeft + recRight);
        return max(recLeft, recRight);
    }
};
