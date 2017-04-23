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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        sum(root, tilt);
        return tilt;
    }
    
    int sum(TreeNode* r, int &tilt){
        if( r == nullptr) return 0;
        int left = sum(r->left, tilt);
        int right = sum(r->right, tilt);
        
        tilt += abs(left-right);
        return r->val + left + right;
    }
};
