class Solution {
public:
    string maskPII(string S) {
        int i=0;
        
        while(i < S.size() && S[i] != '@') ++i;
        
        if(i == S.size())
        {
            vector<char> numbers;
            for(auto ch : S) if(isdigit(ch)) numbers.push_back(ch);
            
            string replaced = "";
            i = numbers.size()-1;
            for(int j=0; j<4; ++j, --i) replaced = numbers[i] + replaced;
            
            for(int j=0; j+4 < numbers.size(); ++j)
            {
                if(j%3 == 0) replaced = "-" + replaced;
                replaced = "*" + replaced;
                
            }
            
            if(numbers.size() > 10) replaced = "+" + replaced;
            
            return replaced;
        }
        
        string replaced = "";
        replaced += tolower(S[0]);
        replaced += "*****";
        replaced += tolower(S[i-1]);
        while(i<S.size())
        {
            replaced += tolower(S[i]);
            ++i;
        }
        
        return replaced;
    }
};
