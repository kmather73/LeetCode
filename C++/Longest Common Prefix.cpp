class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        int i=0;        
        while(true) {
            for(int j=0; j < strs.size(); ++j) {
                if(i >= strs[j].size() || strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
            ++i; 
        }
    }
};
