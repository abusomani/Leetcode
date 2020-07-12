/*
45 degree line is y = x + b
135 degree line is y = -x + b
in another word, 45 degree y - x is constant, and 135 degree y + x is constant.
Here b is shifted to [0~2n), so y-x and y+x can be trackable.
*/
class Solution
{
private:
    int boardSize;
    int ans = 0;
    vector<int> cols, leftDiag, rightDiag;

public:
    void dfs(vector<string> &board, int row)
    {
        if (row == boardSize)
        {
            ans++;
            return;
        }

        for (int col = 0; col < boardSize; col++)
        {
            int id1 = col - row + boardSize;
            int id2 = col + row;
            if (cols[col] || leftDiag[id1] || rightDiag[id2])
                continue;

            cols[col] = true;
            leftDiag[id1] = true;
            rightDiag[id2] = true;
            dfs(board, row + 1);
            cols[col] = false;
            leftDiag[id1] = false;
            rightDiag[id2] = false;
        }
    }

    int totalNQueens(int n)
    {
        boardSize = n;
        cols.resize(n);
        leftDiag.resize(2 * n);  // y = -x + b ( \ )
        rightDiag.resize(2 * n); // y = x + b ( / )
        vector<string> board;
        for (int i = 0; i < boardSize; i++)
            board.push_back(string(n, '.'));

        dfs(board, 0);
        return ans;
    }
};