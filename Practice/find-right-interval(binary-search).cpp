class Solution
{
public:
    int lower(vector<pair<int, int>> &V, int val)
    {
        int N = V.size(), l = 0, r = N - 1, ans = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (V[mid].first >= val)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int N = intervals.size();
        vector<int> res(N, -1);
        if (N == 0)
            return res;
        vector<pair<int, int>> start;
        int idx = 0;
        for (auto &i : intervals)
        {
            start.push_back({i[0], idx});
            idx++;
        }
        sort(start.begin(), start.end());
        idx = 0;
        for (auto &i : intervals)
        {
            int id = lower(start, i[1]);
            if (id != -1)
                res[idx] = start[id].second;
            idx++;
        }
        return res;
    }
};
