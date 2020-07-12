class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int ans = 0, N = grid.size(), M = N ? grid[0].size() : 0;
        if (N == 0 or M == 0)
            return 0;

        vector<int> top(N, -1), left(M, -1);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                top[i] = max(top[i], grid[i][j]);
                left[j] = max(left[j], grid[i][j]);
            }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                ans += min(top[i], left[j]) - grid[i][j];
            }

        return ans;
    }
};