class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasLeft = 0;
        int start = 0;
        int totalGas = 0, totalDist = 0;
        
        for( int i = 0; i < n; ++i){
            totalGas += gas[i];
            totalDist += cost[i];
            
            gasLeft += gas[ i ] - cost[ i ];
            if ( gasLeft < 0 ) {
                gasLeft = 0;
                start = i+1;
            }
        }
        return totalGas < totalDist? -1 : start;
    }
};
