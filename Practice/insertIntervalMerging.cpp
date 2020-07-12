/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int N = intervals.size();
        vector<vector<int>> result;
        int start = newInterval[0], end = newInterval[1], idx = 0;
        while (idx < N)
        {
            vector<int> interval = intervals[idx];
            if (end < interval[0])
            { // our start and end are smaller
                result.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
            if (start > interval[1])
            { // start and end are bigger
                result.push_back(interval);
            }
            if ((start >= interval[0] and start <= interval[1]) or (end >= interval[0] and end <= interval[1]))
            {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
            idx++;
        }

        result.push_back({start, end});
        return result;
    }
};