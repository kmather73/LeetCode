class Solution {
public:
    vector<string> findOcurrences(const string &text, const string &first, const string &second) {
        auto idx = 0;
        auto n = text.size();
        auto toFind = first + " " + second + " ";
        auto len = toFind.size();
        vector<string> thirdWords;
        while(idx != string::npos)
        {
            idx = text.find(toFind, idx);
            if(idx != string::npos)
            {
                auto thirdStartIdx = idx + len;
                if(thirdStartIdx < n)
                {
                    auto stopIdx = text.find(' ', thirdStartIdx);
                    thirdWords.push_back(text.substr(thirdStartIdx, stopIdx - thirdStartIdx));
                }
                idx = thirdStartIdx;
            }
        }
        
        return thirdWords;
    }
};
