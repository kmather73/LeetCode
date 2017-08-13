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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
    
    TreeNode* build(vector<int> &nums, int start, int end){
        if(start >= end) return nullptr;
        int i = start;
        
        for(int j = start+1; j < end; ++j){
            if(nums[i] < nums[j]) i = j;
        }
        
        TreeNode* r = new TreeNode(nums[i]);
        r->left = build(nums, start, i);
        r->right = build(nums, i+1, end);
        return r;
    }
};
