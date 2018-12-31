class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*> stack;
        stack.push(root);
        int sum = 0;
        
        while(stack.size())
        {
            auto r = stack.top(); stack.pop();
            
            if(r)
            {
                if(r->val >= L && r->val <= R) sum += r->val;
                if(r->val > L) stack.push(r->left);
                if(r->val < R) stack.push(r->right);
            }
        }
        return sum;
    }
};
