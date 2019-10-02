class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> keyChars {{'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}};
        
        unordered_map<char, int> counts{{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for(auto ch : text)
        {
            if(keyChars.count(ch)) ++counts[ch];
        }
        
        int count = INT_MAX;
        for(auto p : counts)
        {
            count = min(count, p.second / keyChars[p.first]);
        }
        
        return count;
    }
};
