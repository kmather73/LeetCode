#include<cmath>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty() ){
            return 0;
        }
        int start{0};
        int length{1};
        
        int index[256]{};
        for(int i =0; i!=256; i++){
            index[i]=-1;//set up the position of where each character was last seen and set it to -1 to start.
        }

        for(int i = 0; i!= s.length(); ++i){
            int temp = s.at(i);
            if(index[temp]<start ){//Have we seen this character before relvtive to the starting positon of our subsequence?
                length = fmax(length, i - start + 1); //update length if needed.
            }
            else if(index[temp] >= start){
                start = index[temp] + 1;// update the position of where the subsequence starts based on where the previous character was. 
            }
            index[temp] = i;//update the latest index of a character in the subsequence seen so far.
        }
        return length;
    }
};
