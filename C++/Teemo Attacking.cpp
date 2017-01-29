class Solution {
public:
    int findPosisonedDuration(vector<int>& ts, int duration) {
        int tp = 0, pe = 0;
        
        for(int i=0; i<ts.size(); ++i){
            int delta = duration;
            if(ts[i] < pe){
                delta -= pe - ts[i];
            }
            
            tp += delta;
            pe = ts[i] + duration;
        }
        return tp;
    }
};
