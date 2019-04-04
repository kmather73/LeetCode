class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> v{1, 0};
        
        for(auto ch : S)
        {
            if(v[1] + widths[ch - 'a'] > 100)
            {
                ++v[0];
                v[1] = widths[ch - 'a'];
            }
            else
            {
                v[1] += widths[ch - 'a'];
            }
        }
        
        if(v[1] == 100)
        {
            ++v[0];
            v[1] = 0;
        }
        
        return v;
    }
};
