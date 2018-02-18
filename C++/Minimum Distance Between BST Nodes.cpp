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
private:
    bool leftMost;    
public:
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        leftMost = true;
        long dist = INT_MAX;
        int left = INT_MIN;
        inorder(root, left, dist);
        return dist;
    }
    
    void inorder(TreeNode* r, int& left, long& dist)
    {
        if(r == nullptr) return;
        inorder(r->left, left, dist);
        if(leftMost)
        {
            leftMost = false;
        }
        dist = min(dist, (long)r->val - left);
        left = r->val;
        
        inorder(r->right, left, dist);
        
    }
};
