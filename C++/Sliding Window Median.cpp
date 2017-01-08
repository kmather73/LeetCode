class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mp;
        vector<double> med;
        
        for(int i=0; i<k-1; ++i) mp.insert(nums[i]);
        
        for(int i=k-1; i< nums.size(); ++i){
            mp.insert(nums[i]);
            
            auto itb = mp.begin();
            auto ite = mp.end();
            advance(itb, (k-1)/2);
            advance(ite, -(k+1)/2);
            
            double avg = ((long)(*itb) + (*ite)) / 2.0;
            med.push_back(avg);
            auto it =  mp.find(nums[i-k+1]);
            mp.erase( it );
            
        }
        
        return med;
    }
};
