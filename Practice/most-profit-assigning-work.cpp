class Solution
{
public:
    bool static comp(pair<int, int> &a, pair<int, int> &b)
    {
        return (a.first < b.first);
    }
    int lower(vector<pair<int, int>> &V, int &work)
    {
        int N = V.size(), l = 0, r = N - 1, idx = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (V[mid].first > work)
                r = mid - 1;
            else
                idx = mid, l = mid + 1;
        }
        return idx;
    }
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int N = profit.size();
        vector<pair<int, int>> V;
        for (int i = 0; i < N; i++)
            V.push_back({difficulty[i], profit[i]});

        sort(V.begin(), V.end(), comp);

        vector<int> prefix(N);
        prefix[0] = V[0].second;
        for (int i = 1; i < N; i++)
            prefix[i] = max(prefix[i - 1], V[i].second);

        int ans = 0;
        for (auto &work : worker)
        {
            int idx = lower(V, work);
            ans += idx == -1 ? 0 : prefix[idx];
        }
        return ans;
    }
};