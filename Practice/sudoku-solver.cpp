class Solution
{
private:
    unordered_map<int, unordered_set<int>> row, col, box;

public:
    bool dfs(vector<vector<char>> &board, int pos)
    {
        // pos can uniquely identify [x, y] => x = pos /9 and y = pos % 9
        if (pos >= 81)
            return true;

        int x = pos / 9;
        int y = pos % 9;

        if (board[x][y] != '.')
            return dfs(board, pos + 1);

        for (int num = 1; num <= 9; num++)
        {
            if (!row[x].count(num) and !col[y].count(num) and !box[3 * (x / 3) + y / 3].count(num))
            {
                row[x].insert(num);
                col[y].insert(num);
                box[3 * (x / 3) + y / 3].insert(num);
                board[x][y] = num + '0';
                if (dfs(board, pos + 1))
                    return true;
                board[x][y] = '.';
                row[x].erase(num);
                col[y].erase(num);
                box[3 * (x / 3) + y / 3].erase(num);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        int count = 81; // total 81 numbers should be there
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    count--; // number already present
                    row[i].insert(num);
                    col[j].insert(num);
                    box[3 * (i / 3) + j / 3].insert(num); //i/3 is int division hence
                }

        assert(dfs(board, 0) == true);
    }
};