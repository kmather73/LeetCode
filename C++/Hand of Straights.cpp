class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0) return false;
        
        int groupSize = hand.size() / W;
        
        vector<vector<int>> hands(groupSize);
        sort(hand.begin(), hand.end());
        
        int j=0;
        int i=0;
        while(i < hand.size())
        {
            hands[j].push_back(hand[i++]);
            int k=1;
            while(i < hand.size() && hand[i-1] == hand[i])
            {
                if(k + j >= groupSize) return false;
                hands[k + j].push_back(hand[i++]);
                ++k;
            }
            
            while(j < groupSize && hands[j].size() >= W) ++j;
        }
        
        for(int i=0; i < groupSize; ++i)
        {
            if(hands[i].size() != W) return false;
            for(int j=1; j < W; ++j) 
                if(hands[i][j-1]+1 != hands[i][j]) return false;
        }
        
        return true;
    }
};
