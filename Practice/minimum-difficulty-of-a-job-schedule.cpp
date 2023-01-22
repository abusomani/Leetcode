class Solution
{
private:
    unordered_map<int, unordered_map<int, int>> dp;
    int N;
    int dfs(int idx, int d, vector<int> &J)
    {
        if (d == 0 and idx == N)
            return 0;
        if (d == 0 or idx == N)
            return INT_MAX;
        if (dp.count(idx) and dp[idx].count(d))
            return dp[idx][d];
        int mx = J[idx], sm = INT_MAX;
        for (int i = idx; i < N; i++)
        {
            mx = max(mx, J[i]);
            //start a new segment from here
            int val = dfs(i + 1, d - 1, J);
            if (val != INT_MAX)
                sm = min(sm, mx + val);
        }
        return dp[idx][d] = sm;
    }

public:
    int minDifficulty(vector<int> &J, int d)
    {
        N = J.size();
        if (d > N)
            return -1;
        if (d == N)
            return accumulate(J.begin(), J.end(), 0);
        return dfs(0, d, J);
    }
};