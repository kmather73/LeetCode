class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int j = 0;
        for(auto x : arr) j += !x;
        
        for(int i = arr.size()-1; i >= 0 && j > 0; --i)
        {
            if(i+j < arr.size()) arr[i+j] = arr[i];
            j -= !arr[i];
            if(i+j < arr.size()) arr[i+j] = arr[i];
        }
    }
};
