class Solution {
public:
    int countLetters(string S) {
        
        int i = 1;
        int n = S.size();
        int count = n;
        
        while(i < n)
        {
            int j = i;
            while(i < n && S[i-1] == S[i]) 
            {
                ++i;
                count += (i - j);
            }
            i += (i == j);
        }
        
        return count;
    }
};
