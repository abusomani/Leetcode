class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        rows.clear();
        cols.clear();
        box.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    box[3 * (i / 3) + j / 3].insert(ch); // 3 * (i/3)  != i because (i/3) is integer division, so it rounds to 0,3 and 6 only.
                }
            }
        }

        solveSudoku(board, 0);
    }

private:
    unordered_map<int, unordered_set<char>> rows, cols, box;

    bool solveSudoku(vector<vector<char>> &board, int pos)
    {
        if (pos >= 81)
            return true;
        int i = pos / 9; // row number
        int j = pos % 9; // column number
        if (board[i][j] != '.')
            return solveSudoku(board, pos + 1);
        else
        {
            for (char c = '1'; c <= '9'; c++)
            {
                if (rows[i].find(c) == rows[i].end() and
                    cols[j].find(c) == cols[j].end() and
                    box[3 * (i / 3) + j / 3].find(c) == box[3 * (i / 3) + j / 3].end())
                {
                    rows[i].insert(c);
                    cols[j].insert(c);
                    box[3 * (i / 3) + j / 3].insert(c);
                    board[i][j] = c;
                    if (solveSudoku(board, pos + 1))
                        return true;
                    rows[i].erase(c);
                    cols[j].erase(c);
                    box[3 * (i / 3) + j / 3].erase(c);
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
};