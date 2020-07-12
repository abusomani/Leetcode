class Solution
{
public:
    int N, M;
    int numIslands(vector<vector<char>> &grid)
    {
        N = grid.size();
        M = N ? grid[0].size() : 0;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i >= 0 and j >= 0 and i < N and j < M and grid[i][j] == '1')
        {
            grid[i][j] = '0';
            dfs(grid, i - 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
            dfs(grid, i + 1, j);
        }
    }
};