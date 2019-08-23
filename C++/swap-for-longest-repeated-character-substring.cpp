struct Run
{
    int start;
    int length;
    char ch;
    
    Run(char c, int i) : ch(c), start(i), length(1) {}
    int EndPose()
    {
        return start + length;
    }
};

class Solution {
public:
    int maxRepOpt1(const string &text) {
        int i = 0, n = text.size();
        unordered_map<char, vector<Run>> allRuns;
        int maxLen = 0;
        
        while(i < n)
        {
            int j = i + 1;
            Run r(text[i], i);
            while(j < n && text[i] == text[j])
            {
                ++j;
                ++r.length;
            }
            
            maxLen = max(maxLen, r.length);
            vector<Run>& runs = allRuns[r.ch];
            runs.push_back(r);
            for(int k = 1; k < runs.size(); ++k)
            {
                
                auto& A = runs[k-1];
                auto& B = runs[k];
                
                if(A.EndPose() + 1 == B.start)
                {
                    maxLen = max(maxLen, A.length + B.length + 1 * (runs.size() == 3));
                }
                else
                {
                    maxLen = max(maxLen, 1 + max(A.length, B.length));
                }
            }
            
            if(runs.size() == 3)
            {
                runs.erase(runs.begin());
            }
            
            
            i = j;
        }
        
        return maxLen;
    }
};
