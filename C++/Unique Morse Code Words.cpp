class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        
        unordered_set<string> unique;
        
        for(auto word : words)
        {
            unique.insert(ToMorseCode(word));
        }
        return unique.size();
    }
    
    string ToMorseCode(string& str)
    {
        string lookUp[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string morse = "";
        for(char ch : str)
        {
            morse += lookUp[ch - 'a'];
        }
        return morse;
    }
};
