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
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left){
            if(root->val != root->left->val && root->val != root->right->val){
                return min(root->left->val, root->right->val);
            }
            
            int left = findSecondMinimumValue(root->left);
            int right = findSecondMinimumValue(root->right);
            
            if(root->val == root->left->val && root->val != root->right->val){
                if(left != -1) return min(left, root->right->val);
                return root->right->val;
            } 
            
            if(root->val == root->right->val && root->val != root->left->val){
                if(right != -1) return min(right, root->left->val);
                return root->left->val;
            } 
            
            if(left == -1) return right;
            if(right == -1) return left;
            return min(left, right);
        }
        return -1;
    }
};
