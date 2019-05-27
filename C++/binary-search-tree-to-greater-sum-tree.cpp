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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        revInorderDFS(root, sum);
        return root;
    }
    
    int revInorderDFS(TreeNode* r, int &sum)
    {
        if(r == nullptr) return sum;
        
        auto right = revInorderDFS(r->right, sum);
        sum = r->val += right;
        return revInorderDFS(r->left, sum);
    }
};
