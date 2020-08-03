class Solution
{
private:
    int N, M;

public:
    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i >= N or i < 0 or j >= M or j < 0 or !A[i][j])
            return;
        A[i][j] = 0; // mark as 0
        dfs(A, i - 1, j);
        dfs(A, i + 1, j);
        dfs(A, i, j - 1);
        dfs(A, i, j + 1);
    }
    int numEnclaves(vector<vector<int>> &A)
    {
        N = A.size(), M = A[0].size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (i * j == 0 or i == N - 1 or j == M - 1)
                    dfs(A, i, j);

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans += A[i][j];

        return ans;
    }
};