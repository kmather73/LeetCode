class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        unordered_map<string, int> counts;
        string maxStr = "";
        ban.insert("");
        for(auto str : banned) ban.insert(str);
        
        int i = 0;
        int n = paragraph.size();
        
        while (i < n)
        {
            int j = i;
            while(j < n && isalpha(paragraph[j]))
            {
                paragraph[j] = tolower(paragraph[j]);
                ++j;
            }
            
            auto str = paragraph.substr(i, j-i);
            if(!ban.count(str))
            {
                ++counts[str];
                if(counts[str] > counts[maxStr]) maxStr = str;
            }
            i = j + 1;
        }
        
        return maxStr;
    }
};
