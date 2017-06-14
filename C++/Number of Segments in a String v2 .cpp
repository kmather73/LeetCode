class Solution {
public:
    int countSegments(string &s) {
        std::stringstream stream(s);
        
        int count = 0;
        while(!stream.eof()){
            s = "";
            stream >> std::skipws >> s;
            count += s.size() > 0;
        }
        
        return count;
    }
};
