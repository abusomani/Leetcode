class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        int N = intervals.size();
        if (N == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for (auto &interval : intervals)
        {
            if (end < interval[0])
            {
                res.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
            else if (start > interval[1])
                res.push_back(interval);
            else
            {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }
        res.push_back({start, end});
        return res;
    }
};