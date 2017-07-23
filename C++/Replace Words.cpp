class Solution {
public:
    string replaceWords(vector<string>& dict, string &sentence) {
        sort(dict.begin(), dict.end());
        
        stringstream ss(sentence);
        
        string word, newSentence;
        while(ss >> word) {
            string w = "";
            int i=0;
            while(i < word.size() && !binary_search (dict.begin(), dict.end(), w)){
                w = w + word[i]; 
                ++i;
            }
            
            newSentence = newSentence + w + " ";
        }
        
        if(newSentence.size()) newSentence.pop_back();
        
        return newSentence;
    }
};
