class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        if(n != m) return false;
        
        stack<int> s;
        int i=0, j=0;
        
        while(i < n && j < n)
        {
            while(i < n && pushed[i] != popped[j])
            {
                s.push(pushed[i]);
                ++i;
            }
            if(i < n) s.push(pushed[i++]);
            
            while(j < n && s.size() && s.top() == popped[j])
            {
                ++j;
                s.pop();
            }
        }
        
        return i == n && j == n;
    }
};
