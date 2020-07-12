class Solution
{
public:
    static bool compareInterval(const vector<int> &a, const vector<int> &b)
    {
        return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]); // sort according to start time first and then end time
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int N = intervals.size();
        vector<vector<int>> result;
        if (N == 0)
            return result;

        sort(intervals.begin(), intervals.end(), compareInterval);
        vector<int> first = intervals[0];

        for (int i = 1; i < N; i++)
        {
            if (intervals[i][0] > first[1]) // start > end
            {
                result.push_back(first);
                first = intervals[i];
            }
            else
            {
                first[0] = min(first[0], intervals[i][0]);
                first[1] = max(first[1], intervals[i][1]);
            }
        }

        result.push_back(first);

        return result;
    }
};