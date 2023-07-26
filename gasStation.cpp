class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int sum1 = 0, sum2 = 0, beginIndex = -1;
        for(int index = 0; index < size; index += 1) {
            int d = gas[index] - cost[index];
            sum1 += d;
            if(beginIndex == -1) {
                if(d >= 0) {
                    sum2 = d;
                    beginIndex = index;
                }
            }
            else {
                sum2 += d;
                if(sum2 < 0)    beginIndex = -1;
            }
        }
        if(sum1 >= 0)    return beginIndex;
        return -1;
    }
};
