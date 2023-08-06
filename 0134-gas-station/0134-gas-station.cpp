class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int total_gas = 0, total_cost = 0, sum = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        
        return (total_gas >= total_cost) ? start : -1;
    }
};