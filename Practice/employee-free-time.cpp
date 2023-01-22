/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution
{
private:
    vector<Interval> intersectionOfTwoLists(vector<Interval> &A, vector<Interval> &B)
    {
        vector<Interval> result;
        const int N = A.size(), M = B.size();
        if (N == 0 or M == 0)
            return result;
        int i = 0, j = 0;
        while (i < N and j < M)
        {
            if (A[i].end < B[j].start)
                i++;
            else if (A[i].start > B[j].end)
                j++;
            else
            {
                int start = max(A[i].start, B[j].start), end = min(A[i].end, B[j].end);
                result.push_back({start, end});
                if (A[i].end > B[j].end)
                    j++;
                else
                    i++;
            }
        }
        return result;
    }

public:
    vector<Interval> generateFreeTimes(vector<Interval> &A)
    {
        vector<Interval> free;
        int start = INT_MIN, end = INT_MAX;
        for (auto &interval : A)
        {
            if (end >= interval.start)
            {
                free.push_back({start, min(end, interval.start)});
                start = interval.end;
                end = INT_MAX;
            }
        }
        // last free time from start to inf
        free.push_back({start, end});
        return free;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        vector<vector<Interval>> freeTimes;
        for (auto &interval : schedule)
            freeTimes.push_back(generateFreeTimes(interval));
        vector<Interval> result = freeTimes[0];
        for (int i = 1; i < freeTimes.size(); i++)
            result = intersectionOfTwoLists(result, freeTimes[i]);

        vector<Interval> finiteResult;
        for (auto &interval : result)
            if (!(interval.start == INT_MIN or interval.end == INT_MAX or interval.start == interval.end))
                finiteResult.push_back(interval);

        return finiteResult;
    }
};