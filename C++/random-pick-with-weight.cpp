class Solution {
vector<int> weights;
int total;    
    public:
    Solution(vector<int>& w) {
        weights.push_back(w[0]-1);
        for(int i = 1; i < w.size(); ++i) weights.push_back(w[i] + weights.back());
    }
    
    int pickIndex() {
        int idx = rand() % (1 + weights.back());
        auto it = lower_bound(weights.begin(), weights.end(), idx);
        return it - weights.begin();
    }
};
