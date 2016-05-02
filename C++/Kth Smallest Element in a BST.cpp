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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        kthinorder( root, k, ans);
        return ans;
    }
    
    void kthinorder(TreeNode* root, int &k, int &val){
        if( k <= 0 )
            return;
        
        //Go left if possible
        if( root->left != nullptr )
            kthinorder( root->left, k, val);
         
        
        //Are we at the desired node
        if( k == 1 )
            val = root->val;
        
        //Have visited one more node
        --k;
        
        //Go right if possible
        if( root->right != nullptr )
            kthinorder( root->right, k, val);
    }
};
