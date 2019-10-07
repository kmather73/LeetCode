class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> lens;
        int maxLen = 0;
        int n = arr.size();
        
        for(int i = n - 1; i >= 0; --i)
        {
            auto num = arr[i];
            auto nextEle = num + difference; 
            lens[num] = 1 + lens[nextEle];
            maxLen = max(maxLen, lens[num]);
        }
        
        return maxLen;
    }
};
