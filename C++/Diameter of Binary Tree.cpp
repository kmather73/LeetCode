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

    int utill(TreeNode* r, int &m){
        if(r == nullptr) return 0;
        
        int left = utill(r->left, m);
        int right = utill(r->right, m);
        
        m = std::max(m, left + right);
        
        return 1 + max(left, right);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int m=0;
        utill(root, m);
        
        return m;
    }
};
