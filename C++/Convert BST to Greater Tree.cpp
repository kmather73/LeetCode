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

    void postOrder(TreeNode* r, int &sum){
        if(r == nullptr) return;
        
        postOrder(r->right, sum);
        sum += r->val;
        r->val = sum;
        postOrder(r->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        postOrder(root, sum);
        return root;
    }
};
