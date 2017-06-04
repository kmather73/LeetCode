class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        fb.insert(fb.begin(), 0);
        fb.push_back(0);
        int count = 0;
        
        for(int i=1; 1+i < fb.size(); ++i) {
            if(fb[i-1] == 0 && fb[i+1] == 0 && fb[i] == 0){
                count++;
                fb[i] = 1;
            } 
        }
        
        return count >= n;
    }
};
