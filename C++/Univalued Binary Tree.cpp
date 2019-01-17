class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        bool right = root->right ? root->val == root->right->val : true;
        bool left = root->left ? root->val == root->left->val : true;
        return left && right && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
