class Solution
{
private:
    int N, M, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    bool isValid(int x, int y)
    {
        return (x >= 0 and x < N and y >= 0 and y < M);
    }

public:
    int dfs(vector<vector<int>> &grid, int x, int y, int empty)
    {
        if (grid[x][y] == 2)
            return empty == 0 ? 1 : 0;
        int val = grid[x][y], res = 0;
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i], Y = y + dy[i];
            if (isValid(X, Y) and grid[X][Y] != -1)
                res += dfs(grid, X, Y, empty - 1);
        }
        grid[x][y] = val;
        return res;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        N = grid.size(), M = grid[0].size();
        int src_X, src_Y, empty = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 1)
                    src_X = i, src_Y = j;
                else if (grid[i][j] != -1)
                    empty++;
            }

        return dfs(grid, src_X, src_Y, empty);
    }
};