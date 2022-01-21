class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1 2 3 4 5 1 2 3 4 5
        // 3 4 5 1 2 3 4 5 1 2
        int n = (int)(gas.size());
        int gas_sum = 0, cost_sum = 0;
        for (int i = 0; i < n; ++i) {
            gas_sum += gas[i];
            cost_sum += cost[i];
        }
        if (gas_sum < cost_sum) return -1;
        int ans = 0;
        int sum_now = 0;
        for (int i = 0; i < n; ++i) {
            sum_now += (gas[i] - cost[i]);
            if (sum_now < 0) {
                ans = i + 1;
                sum_now = 0;
            }
        }
        return ans;

    }
};