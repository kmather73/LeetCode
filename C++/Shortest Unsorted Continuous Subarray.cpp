class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); ++i) v.push_back(i);
        if(is_sorted(nums.begin(), nums.end())) return 0;
        sort(v.begin(), v.end(), [&](int a, int b){return nums[a] < nums[b];});
        
        
        int i=0;
        while(i < nums.size() && v[i] == i){
            ++i;
        }
        
        int j = nums.size()-1;
        while(j >=0 && v[j] == j){
            --j;
        }
        
        return j-i+1;
    }
};
