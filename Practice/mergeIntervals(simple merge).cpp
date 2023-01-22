class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int N = intervals.size();
        vector<vector<int>> result;
        if (N == 0)
            return result;

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < N; i++)
        {
            if (intervals[i][0] > end)
            {
                result.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back(vector<int>{start, end});
        return result;
    }
};