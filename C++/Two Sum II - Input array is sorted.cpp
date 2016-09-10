class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, j;
        i=0, j=numbers.size()-1;
        
        while(numbers[i]+numbers[j] != target) {
            if (numbers[i]+numbers[j] < target) ++i;
            else --j;
        }
        
        std::vector<int> v {i+1,j+1};
        return v;
    }
};
