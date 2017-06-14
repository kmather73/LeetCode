class Solution {
public:
    bool detectCapitalUse(const string &word) {
      if(word.size() == 0) return true;
      
      bool hasCaps = false;
      bool isAllUpper = word[0] >= 'A' && word[0] <= 'Z';
      bool isAllLower = !isAllUpper;
      
      for(int i=1; i<word.size(); ++i){
          char ch = word[i];
          hasCaps |= ch >= 'A' && ch <= 'Z';
          isAllLower &= ch < 'A' && ch > 'Z';
          isAllUpper &= ch >= 'A' && ch <= 'Z';
      }
      
      return isAllLower || isAllUpper || !hasCaps;
    }
};
