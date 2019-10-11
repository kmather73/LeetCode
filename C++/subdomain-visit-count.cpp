class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        
        for(auto s : cpdomains)
        {
            int count = 0;
            int i = 0;
            while(s[i] != ' ')
            {
                count = count * 10 + (s[i] - '0');
                ++i;
            }
            
            int j = s.size() - 1;
            while(i < j)
            {
                while(s[j] != '.' && s[j] != ' ') --j;
                
                counts[s.substr(j+1)] += count;
                --j;
            }
        }
        
        vector<string> domains;
        for(auto p : counts) domains.push_back(to_string(p.second) + " " + p.first);
        
        return domains;
    }
};
