class Solution {
private:
    vector<int> table;
public:
    Solution(vector<int> nums) {
        table = nums;
    }
    
    int pick(int target) {
        vector<int> index;
        for(size_t i=0; i < table.size(); ++i){
            if(table[i] == target) index.push_back(i);
        }
        
        int n = index.size();
        return index[rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
