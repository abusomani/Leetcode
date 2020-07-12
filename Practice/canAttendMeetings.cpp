class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end) // [1,13][13,15] => true
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
                return false;
        }
        return true;
    }
};