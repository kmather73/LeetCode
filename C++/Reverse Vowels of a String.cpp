class Solution {
std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

public:
    string reverseVowels(string s) {
        std::stack<char> st;
        
        for(char c : s){
            if( vowels.find(c) != vowels.end() )
                st.push(c);
        }
        
        for(int i=0; i < s.size(); ++i){
            if( vowels.find( s[i] ) != vowels.end() ){
                s[i] = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};
