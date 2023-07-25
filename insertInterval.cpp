class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        vector<vector<int>> ans;
        int startVal = -1, endVal = -1;
        for(int index = 0; index < size; index += 1) {
            if(startVal == -1 && newInterval[0] <= intervals[index][1]) {
                if(intervals[index][0] <= newInterval[0])    startVal = intervals[index][0];
                else    startVal = newInterval[0];
            }
            if(endVal == -1 && newInterval[1] <= intervals[index][1]) {
                if(intervals[index][0] <= newInterval[1]) {
                    endVal = intervals[index][1];
                    ans.push_back({startVal, endVal});
                }
                else {
                    endVal = newInterval[1];
                    ans.push_back({startVal, endVal});
                    ans.push_back(intervals[index]);
                }
                continue;
            }
            if(startVal == -1 || endVal != -1)    ans.push_back(intervals[index]);
        }
        if(startVal == -1 && endVal == -1)    ans.push_back(newInterval);
        if(startVal != -1 && endVal == -1)    ans.push_back({startVal, newInterval[1]});
        return ans;
    }
};
