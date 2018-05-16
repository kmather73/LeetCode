class Solution {
public:
    string findReplaceString(string &S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string str;
        int i=0;
        int j=0;
        
        vector<int> srt;
        for(int i=0; i < indexes.size(); ++i) srt.push_back(i);
        
        std::sort(srt.begin(), srt.end(), 
                  [&](const int &a, const int &b) -> bool 
                  {
                      return indexes[a] < indexes[b];
                  });
        while(i < S.size())
        {
            
            while(j < indexes.size() && i > indexes[srt[j]]) ++j;
            
            if(j < indexes.size() && i == indexes[srt[j]] && 0 == S.compare(i, sources[srt[j]].size(), sources[srt[j]]))
            {
                str += targets[srt[j]];
                i += sources[srt[j]].size();
                ++j;
            }
            else
            {
                str += S[i];
                ++i;
            }
        }
        
        return str;
    }
};
