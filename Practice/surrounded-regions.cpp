class Solution
{
private:
    int N, M;
    unordered_set<string> St;

public:
    string toString(int x, int y)
    {
        return to_string(x) + "_" + to_string(y);
    }
    void dfs(vector<vector<char>> &board, int x, int y, vector<vector<bool>> &dp)
    {
        if (x < 0 or x >= N or y < 0 or y >= M or board[x][y] == 'X' or St.count(toString(x, y)))
            return;

        St.insert(toString(x, y));
        dp[x][y] = true;
        dfs(board, x - 1, y, dp);
        dfs(board, x + 1, y, dp);
        dfs(board, x, y - 1, dp);
        dfs(board, x, y + 1, dp);
    }
    void solve(vector<vector<char>> &board)
    {
        N = board.size();
        M = N ? board[0].size() : 0;
        if (N == 0 or M == 0)
            return;
        vector<vector<bool>> dp(N, vector<bool>(M, false)); // false means cross, true means valid 'O'

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (i == 0 or j == 0 or i == (N - 1) or j == (M - 1))
                    dfs(board, i, j, dp);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] = dp[i][j] ? 'O' : 'X';
    }
};