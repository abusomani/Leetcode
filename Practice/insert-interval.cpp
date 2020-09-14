class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int N = intervals.size(), start = newInterval[0] , end = newInterval[1], idx = 0;
        while(idx < N)
        {
            if(intervals[idx][1] < start)
               res.push_back(intervals[idx]); 
            else if(intervals[idx][0] > end)
            {
                res.push_back({start, end}); 
                start = intervals[idx][0];
                end = intervals[idx][1];
            }
            else
            {
                start = min(start, intervals[idx][0]);
                end = max(end, intervals[idx][1]);
            }
            idx++;
        }
        res.push_back({start, end});
        return res;
    }
};