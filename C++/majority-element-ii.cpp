class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> votes{0,0};
        vector<int> n{0,0};
        for(auto num : nums)
        {
            if(n[0] == num) ++votes[0];
            else if(n[1] == num) ++votes[1];
            else if(!votes[0])
            {
                ++votes[0];
                n[0] = num;
            }
            else if(!votes[1])
            {
                ++votes[1];
                n[1] = num;
            }
            else
            {
                --votes[0];
                --votes[1];
            }
        }
        
        vector<int> counts{0,0};
        for(auto num : nums)
        {
            counts[0] += n[0] == num;
            counts[1] += n[1] == num;
        }
        
        if(counts[1] <= nums.size() /3) n.erase(n.begin()+1);
        if(counts[0] <= nums.size() /3) n.erase(n.begin());
        if(n.size() == 2 && n[0] == n[1]) n.pop_back();
        return n;
    }
};
