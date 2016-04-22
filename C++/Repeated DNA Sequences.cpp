#define LIMIT (0xFFFFF)
#define START (9)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<std::string> subStr;
        std::unordered_map<int, int> mymap;
        std::unordered_map<int,int>::iterator it;
        
        int vals[65+26];
        vals['A'] = 0, vals['C'] = 1, vals['G'] = 2, vals['T'] = 3;
        int val = 0;
        
        for(int i = 0; i < START && i < s.size(); ++i){
            val = (val << 2) + vals[ s[i] ];
        }
        
        
        for(int i = START; i < s.size(); ++i){
            val = LIMIT&(val << 2) + vals[ s[i] ];
            it = mymap.find(val);
            
            
            if (it != mymap.end() && mymap[val] != -1){
                mymap[val] = -1;
                subStr.push_back( s.substr(i-9, 10) );
            } else if(it == mymap.end()){
                 mymap[ val ] = 1;
            }
        }
        
        return subStr;
    }
};
