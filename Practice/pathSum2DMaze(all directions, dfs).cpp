class Solution
{
public:
    int dfs(int i, int j, int N, int M, vector<vector<int>> &grid)
    {
        if (grid[i][j] == 0)
            return 0;

        int orig = grid[i][j], result = 0;
        grid[i][j] = 0;
        if (i < N - 1)
            result = max(result, dfs(i + 1, j, N, M, grid)); // down
        if (j < M - 1)
            result = max(result, dfs(i, j + 1, N, M, grid)); // right
        if (i > 0)
            result = max(result, dfs(i - 1, j, N, M, grid)); // up
        if (j > 0)
            result = max(result, dfs(i, j - 1, N, M, grid)); // left
        grid[i][j] = orig;                                   // backtrack

        return result + orig;
    }

    int getMaximumGold(vector<vector<int>> &A)
    {
        int N = A.size(), M = A[0].size();
        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (A[i][j])
                    ans = max(ans, dfs(i, j, N, M, A));
        return ans;
    }
};