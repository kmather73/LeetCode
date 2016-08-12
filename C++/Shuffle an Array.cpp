class Solution {
private:
    vector<int> orig;
    
public:
    Solution(vector<int> nums) {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> randShuf( orig );
        for(int i = orig.size()-1; i > 0; --i){
            int j = rand() % (i+1);
            std::swap(randShuf[i], randShuf[j]);
        }
        
        return randShuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
