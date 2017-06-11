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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        int sum = t1->val + t2->val;
        
        TreeNode* r = new TreeNode(sum);
        
        r->left = mergeTrees(t1->left, t2->left);
        r->right = mergeTrees(t1->right, t2->right);
        
        return r;
    }
};
