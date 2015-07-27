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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> preOrder;
       preorderTraversalUtill(root, preOrder);
       return preOrder;
    }
    void preorderTraversalUtill(TreeNode* root, vector<int>& preOrder){
        if(root == NULL)
            return;
        preOrder.push_back(root->val);
        preorderTraversalUtill(root->left, preOrder);
        preorderTraversalUtill(root->right, preOrder);
        
    }
};
