class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int num=0, sum=0;
        DFS(root, num, sum);
        return sum;
    }
    
    void DFS(TreeNode* r, int &num, int& sum)
    {
        if(r == nullptr) return;
        
        num = (num << 1) + r->val;
        if(!r->left && !r->right) sum += num;
        DFS(r->left, num, sum);
        DFS(r->right, num, sum);
        num = (num - r->val) >> 1;
    }
};
