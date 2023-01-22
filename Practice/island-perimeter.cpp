class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        const int N = grid.size(), M = N ? grid[0].size() : 0;
        if (N == 0 or M == 0)
            return ans;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j])
                {
                    ans += 4;
                    for (int k = 0; k < 4; k++)
                        if (isValid(i + dx[k], j + dy[k], N, M) and grid[i + dx[k]][j + dy[k]])
                            ans--;
                }

        return ans;
    }
};