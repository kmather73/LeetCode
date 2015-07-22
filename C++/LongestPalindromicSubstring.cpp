class Solution {
public:
    string longestPalindrome(string s) {
        int left, *temp = (int*) malloc(sizeof(int));
        int length, maxLength = 0;
        int sLength = s.size();
        
        for(int i = 0; i < sLength; ++i){
            if(sLength - i < maxLength>>1)
                break;
            length = palindormeAt(s, i, temp);
            if(length > maxLength){
                maxLength = length;
                left = *temp;
            }
        }
        return s.substr(left, maxLength);
    }
    
    int palindormeAt(string s, int leftPosition, int* position){
        int length = s.size();
        int rightPosition = leftPosition;
        
        while(rightPosition + 1 < length && s.at(rightPosition) == s.at(rightPosition + 1) )
            ++rightPosition;
        while(leftPosition >= 0 && rightPosition < length && s.at(leftPosition) == s.at(rightPosition) ){
            --leftPosition;
            ++rightPosition;
        }
        
        *position = ++leftPosition;
        return rightPosition - leftPosition;
    }
};
