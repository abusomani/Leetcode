class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int N = intervals.size();
        if (N <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < N; i++)
        {
            if (start > intervals[i][1])
                result.push_back(intervals[i]);
            else if (end < intervals[i][0])
            {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};