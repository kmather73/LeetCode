class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string s, best = "{}";
        DFS(root, s, best);
        reverse(best.begin(), best.end());
        return best;
    }
    
    void DFS(TreeNode* r, string& s, string& best)
    {
        if(r == nullptr) return;
        
        s.push_back(r->val + 'a');
        DFS(r->left, s, best);
        DFS(r->right, s, best);
        
        if(!(r->left || r->right))
        {
             if(Less(s, best)) best = s;
        }
        
        s.pop_back();
    }
    
    bool Less(string &s, string &t)
    {
        int n = s.size()-1;
        int m = t.size()-1;
        
        while(n >= 0 && m >=0)
        {
            if(s[n] > t[m]) return false;
            else if(s[n] < t[m]) return true;
            --n, --m;
        }
        
        return n < 0 && m >= 0;
    }
};
