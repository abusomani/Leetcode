class Solution
{
private:
    int boardSize;
    int ans = 0;

public:
    bool isValid(vector<string> &board, int x, int y)
    {
        for (int i = 0; i < boardSize; i++)
            if (board[x][i] == 'Q' or board[i][y] == 'Q')
                return false;

        for (int i = x, j = y; i >= 0 and j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = x, j = y; i >= 0 and j < boardSize; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void dfs(vector<string> &board, int row)
    {
        if (row == boardSize)
        {
            ans++;
            return;
        }

        for (int i = 0; i < boardSize; i++)
        {
            if (isValid(board, row, i))
            {
                board[row][i] = 'Q';
                dfs(board, row + 1);
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n)
    {
        boardSize = n;
        vector<string> board;
        for (int i = 0; i < boardSize; i++)
            board.push_back(string(n, '.'));

        dfs(board, 0);
        return ans;
    }
};