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
    int getMinimumDifference(TreeNode* root) {
        long int min = INT_MIN;
        long int max = INT_MAX;
        long int diff = INT_MAX;
        getMinDiff(root, min, max, diff);
        
        return int(diff);
    }
    
    void getMinDiff(TreeNode* root, long int &min, long int &max, long int &diff){
        if(root == nullptr) {
            min = INT_MAX;
            max = INT_MIN;
            return;
        }
        
        long int leftMax, rightMin; 
        getMinDiff(root->left, min, leftMax, diff);
        getMinDiff(root->right, rightMin, max, diff);
        
        long diffL = root->val - leftMax;
        long diffR = rightMin - root->val;
        diff = std::min(diff, std::min(diffL, diffR));
        
        min = std::min(min, (long) root->val);
        max = std::max(max, (long) root->val);
    }
};
