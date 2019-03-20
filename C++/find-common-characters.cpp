class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> v(26, INT_MAX), t(26);
            
        for(string a : A) 
        {
            for(char ch : a)
            {
                ++t[ch - 'a'];
            }
            for(int i = 0; i < v.size(); ++i) 
            {
                v[i] = min(v[i], t[i]);
                t[i] = 0;
            }
        }
        
        vector<string> common;
        for(int i = 0; i < v.size(); ++i) 
        {
            char ch = 'a' + i;   
            while(v[i] > 0) common.push_back(string(1, ch)), --v[i];
        }
        
        return common;
    }
};
