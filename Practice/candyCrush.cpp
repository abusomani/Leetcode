class Solution
{
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        int N = board.size(), M = board[0].size();
        bool isChanged = false;
        while (true)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j + 2 < M; j++)
                {
                    int val = abs(board[i][j]);
                    if (val != 0 and val == abs(board[i][j + 1]) and val == abs(board[i][j + 2]))
                    {
                        isChanged = true;
                        board[i][j] = -val;
                        board[i][j + 1] = -val;
                        board[i][j + 2] = -val;
                    }
                }
            }

            for (int j = 0; j < M; j++)
            {
                for (int i = 0; i + 2 < N; i++)
                {
                    int val = abs(board[i][j]);
                    if (val != 0 and val == abs(board[i + 1][j]) and val == abs(board[i + 2][j]))
                    {
                        isChanged = true;
                        board[i][j] = -val;
                        board[i + 1][j] = -val;
                        board[i + 2][j] = -val;
                    }
                }
            }

            for (int j = 0; j < M; j++)
            {
                int bottom = N - 1;
                for (int i = N - 1; i >= 0; i--)
                {
                    if (board[i][j] > 0)
                        board[bottom--][j] = board[i][j];
                }
                while (bottom >= 0)
                    board[bottom--][j] = 0;
            }

            if (!isChanged)
                break;
            isChanged = false;
        }
        return board;
    }
};