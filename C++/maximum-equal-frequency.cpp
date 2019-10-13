class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> counts;
        unordered_map<int, int> freq;
        unordered_set<int> seen;
        int maxF = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            auto num = nums[i];
            --freq[counts[num]];
            if(freq[counts[num]] <= 0 )
            {
                freq.erase(counts[num]);
            }
            
            ++counts[num];
            ++freq[counts[num]];
            
            if(counts.size() == 1 || (freq.size() == 1 && freq.begin()->first == 1))
            {
                maxF = i+1;
            }
            else if(freq.size() == 2)
            {
                auto b = freq.begin()->first;
                auto r = (++freq.begin())->first;
                if(r < b)
                {
                    swap(r, b);
                }
                
                if((b == 1 && freq[b] == 1) || (freq[r] == 1 && r - b == 1))
                {
                    maxF = i+1;
                }
            }
        }
        
        return maxF;
    }
};
