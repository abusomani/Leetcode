class Solution
{
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1], board.size(), board[0].size());

        return board;
    }

    void dfs(vector<vector<char>> &board, int i, int j, int N, int M)
    {
        if (!isValid(i, j, N, M))
            return;
        if (board[i][j] == 'E')
        {
            int cnt = 0;
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (isValid(x, y, N, M) and board[x][y] == 'M')
                    cnt++;
            }

            if (cnt)
                board[i][j] = '0' + cnt;
            else
            {
                board[i][j] = 'B';
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    dfs(board, x, y, N, M);
                }
            }
        }
    }
};