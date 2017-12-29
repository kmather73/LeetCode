class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        ops.push_back("0");
        int i=n, j=n, h=n, score=0;
        vector<int> rounds(2);
        
        for(int k=0; k < n; ++k){
            int val = 0;
            bool valid = true;
            if(ops[k] == "C"){
                val = -rounds.back();
                valid = false;
                rounds.pop_back();
            } else if(ops[k] == "D"){
                val = 2*rounds.back();
            } else if(ops[k] == "+"){
                 val = rounds.back() + rounds.rbegin()[1];
            } else {
                val = stoi(ops[k]);
            }
            if(valid) rounds.push_back(val);
            score += val;
        }
        
        return score;
    }
};
