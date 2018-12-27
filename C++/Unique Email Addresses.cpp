class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> canonicalEmails;
        
        for(auto email : emails)
        {
            canonicalEmails.insert(ToCanonicalEmail(email));
        }
        
        return canonicalEmails.size();
    }
    
    string ToCanonicalEmail(string& str)
    {
        string email = "";
        int p = 0;
        while(str[p] != '@')
        {
            if(str[p] == '+') { while(str[p] != '@') ++p; }
            else {
                if(str[p] != '.') email += str[p];
                ++p;
            }
        }
        
        email += str.substr(p);
        return email;
    }
};
