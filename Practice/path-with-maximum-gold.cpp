class Solution
{
private:
    int N, M;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

public:
    bool isValid(int i, int j)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] == 0)
            return 0;

        int value = grid[i][j];
        grid[i][j] = 0;
        int maxsum = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (isValid(x, y))
                maxsum = max(maxsum, value + dfs(grid, x, y));
        }

        grid[i][j] = value;
        return maxsum;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        N = grid.size();
        M = grid[0].size();
        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};