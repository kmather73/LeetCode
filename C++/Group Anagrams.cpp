class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map< std::string, std::vector< std::string >> groups;
        
        for( std::string s: strs){
            std::string temp = s;
            std::sort( temp.begin(), temp.end() );
            
            groups[ temp ].push_back( s );
        }
        
        std::vector< std::vector<string> > anagrams;
        
        for(auto group: groups) {
            std::sort( group.second.begin(), group.second.end() );
            anagrams.push_back( group.second );
        }
            
        return anagrams;
    }
};
