class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {              
        stable_sort(logs.begin(), logs.end(),
             [](const string& a, const string& b)
             {
                 int i, j;
                 auto aWord = IsWordLog(a, i);
                 auto bWord = IsWordLog(b, j);
                 
                 if(aWord && bWord)
                 {
                     auto cmp = a.substr(i+1).compare(b.substr(j+1));
                     if(cmp !=0 ) return cmp < 0;
                         
                     return a.compare(0, i, b, 0, j) < 0;
                 }
                 
                 return aWord;
             });
        return logs;
    }
    
    static inline bool IsWordLog(const string &str, int &i)
    {
        i = str.find(' ');
        return isalpha(str[i+1]);
    }
};
