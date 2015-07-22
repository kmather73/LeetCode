class Solution {
public:
    bool isValid(string s) {
        std::set<char>rightPerens{']' , '}' , ')'};
        std::map<char,char>leftToRightPerens {
            { '[' , ']' },
            { '{' , '}' },
            { '(' , ')' } };
        std::stack<char> perens{};
        
        int position = s.size();
        while(position){
            char temp = s.at(--position);
            
            if(rightPerens.end() != rightPerens.find(temp))
                    perens.push(temp);
            else{
                if(perens.size() == 0 || perens.top() != leftToRightPerens[temp])
                    return false;
                perens.pop();
            }
        }
        return perens.size() == 0;
    }
};
