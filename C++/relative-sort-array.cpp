class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> order;
        for(int i = 0; i < arr2.size(); ++i) 
        {
            order[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(),
            [&order](const int& a, const int& b)
             {
                 auto hasA = order.count(a);
                 auto hasB = order.count(b);
                 if(hasA && hasB) return order[a] < order[b];
                 if(!hasA && !hasB) return a < b;
                 return !hasB;
             });
        return arr1;
    }
};
