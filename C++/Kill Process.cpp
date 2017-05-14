class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> map;
        for(int i=0; i<pid.size(); ++i){
            map[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> toKill;
        stack<int> stack;
        stack.push(kill);
        
        while(stack.size()){
            int top = stack.top(); stack.pop();
            toKill.push_back(top);
            
            for(int x: map[top]){
                stack.push(x);
            }
        }
        return toKill;
    }
};
