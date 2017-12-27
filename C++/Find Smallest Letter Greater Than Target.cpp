class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters.back()) return letters[0];
        int lo = 0, hi = letters.size()-1;
        
        while(hi > lo)
        {
            int mid = (hi-lo)/2 + lo;
            if(letters[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return letters[hi];
    }
};
