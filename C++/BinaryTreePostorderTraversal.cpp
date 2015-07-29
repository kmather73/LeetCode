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
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> postOrder;
        
        inorderTraversal(postOrder, root);
        std::reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
    
    void inorderTraversal(vector<int>& preOrder,TreeNode* root){
        if(!root)
            return;
        preOrder.push_back(root->val);
        inorderTraversal(preOrder, root->right);
        inorderTraversal(preOrder, root->left);
    }
}
