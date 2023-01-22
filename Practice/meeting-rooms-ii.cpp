class Solution
{
public:
    struct compare
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[1] > b[1]; // min heap on end time
        }
    };
    int useHeap(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        priority_queue<vector<int>, vector<vector<int>>, compare> PQ;
        for (auto &interval : intervals)
        {
            if (!PQ.empty() and PQ.top()[1] <= interval[0])
                PQ.pop();
            PQ.push(interval);
        }
        return PQ.size();
    }
    int useMapKadane(vector<vector<int>> &intervals)
    {
        map<int, int> Mp;
        for (auto &interval : intervals)
            Mp[interval[0]]++, Mp[interval[1]]--;

        int ans = 0, sum = 0;
        for (auto &i : Mp)
            sum += i.second, ans = max(ans, sum);
        return ans;
    }
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        // return useHeap(intervals);
        return useMapKadane(intervals);
    }
};