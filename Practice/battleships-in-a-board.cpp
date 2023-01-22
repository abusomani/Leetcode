class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int ans = 0, N = board.size(), M = N ? board[0].size() : 0;
        if (N == 0 or M == 0)
            return 0;
        ans = board[0][0] == 'X';
        for (int i = 1; i < M; i++)
            if (board[0][i] == 'X')
                ans += board[0][i - 1] != 'X';

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j == 0 and board[i][j] == 'X')
                {
                    ans += (board[i - 1][j] != 'X');
                    continue;
                }
                else if (board[i][j] == 'X')
                    ans += (board[i - 1][j] != 'X' and board[i][j - 1] != 'X');
            }
        }
        return ans;
    }
};