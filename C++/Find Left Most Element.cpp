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
    int findLeftMostNode(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> level;
        
        q.push(root);
        level.push(0);
        
        int m=0;
        while(q.size()){
            TreeNode *r = q.front(); q.pop();
            int l = level.front(); level.pop();
            if(r->left) {
                q.push(r->left);
                level.push(l+1);
            }
            
            if(r->right){
                q.push(r->right);
                level.push(l+1);
            }
            
            if(l > m){
                m = l;
                root = r;
            }
        }
        
        return root->val;
        
    }
};
