using DP = vector<vector<bool>>; //unordered_map<int, unordered_map<int,int>>;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        for(auto q : queries)
        {   
            ans.push_back(q.size() >= pattern.size() && Match(q, pattern));
        }
        
        return ans;
    }
    
    bool Match(string &s, string &t)
    {
        DP dp(s.size(), vector<bool>(t.size()));
        return DFS(0, s, 0, t, dp);
    }
      
    bool DFS(int i, string &s, int j, string &t, DP &dp)
    {
        
        if(i == s.size() || j == t.size()) 
        {           
            while(i < s.size())
            {
                if(isupper(s[i++]))
                {
                    return false;
                }
            }
             
            return j >= t.size();
        }
        
        if(dp[i][j]) return true;
        
        if(islower(s[i]))
        {
            dp[i][j] = DFS(i+1, s, j, t, dp);
        }
        
        if(s[i] == t[j])
        {
            dp[i][j] = dp[i][j] || DFS(i+1, s, j+1, t, dp);
        }
        
        return dp[i][j]; 
    }
};
