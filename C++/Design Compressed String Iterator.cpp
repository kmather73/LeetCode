bool isInt(char c ) {
    return c >= '0' && c <='9';
} 

class StringIterator {
    int pos;
    vector<int> counts;
    vector<char> letters;
public:
    StringIterator(const string& cmpS) {
        int i=0, n = cmpS.size();
        pos = 0;
        while(i < n){
            char ch = cmpS[i++];
            letters.push_back(ch);
            
            int sum = 0;
            while(i < n && isInt(cmpS[i])){
                sum = sum*10 + (cmpS[i]-'0');
                ++i;
            }
            counts.push_back(sum);
        }
    }
    
    char next() {
        if(pos >= counts.size()) return ' ';
        
        char ch = letters[pos];
        --counts[pos];
        if(counts[pos] == 0) ++pos;
        
        return ch;
    }
    
    bool hasNext() {
        return pos < counts.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
