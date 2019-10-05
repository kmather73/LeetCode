class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0;
        int n = s.size();
     
        int i = 0;
        int j = 0;
        int cost = 0;
        while(i < n)
        {
           
            cost += abs(s[i] - t[i]);
            ++i;
            
            while(j <= i && cost > maxCost)
            {
                cost -= abs(s[j] - t[j]);
                ++j;
            }
            
            len = max(len, i - j);
        }
        
        return len;
    }
};
