class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int res = 0, tmp = gas[0] - cost[0], sum = tmp;
        for (int i = 1; i < N; ++i)
        {
            sum += gas[i] - cost[i];
            tmp += gas[i] - cost[i];
            if (tmp < 0) {
                tmp = 0;
                res = i;
            }
        }
        return sum >= 0 ? (res + 1) % N : -1; // if sum > 0, there must be a result.becuase the solution is guaranteed to be unique, the result is (res + 1) % N !
    }
};