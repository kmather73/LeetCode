class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        set<string> words;
        backtracking(S, 0, words);
        vector<string> wordss;
        for(auto word: words) wordss.push_back(word);
        return wordss;
    }
    
    void backtracking(string &s, int i, set<string> &words){
        if(i >= s.size()) {
            words.insert(s);
            return;
        }
        
        s[i] = tolower(s[i]);
        backtracking(s, i+1, words);
            
        s[i] = toupper(s[i]);
        backtracking(s, i+1, words);   
    }
};
