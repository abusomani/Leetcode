class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int ans = 0, N = board.size(), M = board[0].size();

        // first row
        for (int i = 0; i < M; i++)
        {
            if (board[0][i] == 'X')
                ans += (i < 1) ? 1 : (board[0][i - 1] == 'X') ? 0 : 1; // either first element or must be new start
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 'X')
                {
                    // part of column, then must have been counted before as row
                    if (board[i - 1][j] == 'X')
                        continue;
                    if (j == 0) // first element then surely count
                        ans++;
                    else if (j >= 1 and board[i][j - 1] != 'X') // new battleship
                        ans++;
                }
            }
        }

        return ans;
    }
};