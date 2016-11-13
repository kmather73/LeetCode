class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for(int i=1; i<n; ++i) leftMin[i] = min(nums[i], leftMin[i-1]);
        
        set<int> rightElements;
        
        for(int i=n-1; i >= 1; --i){
            auto it = rightElements.upper_bound( -nums[i] );
            
            if(it != rightElements.end() && -*it > leftMin[i-1]) return true;
            
            rightElements.insert(-nums[i]);
            
        }
        
        return false;
    }
};
