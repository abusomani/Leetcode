class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows, cols, box;
        bool res = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    res &= (rows[i].find(ch) == rows[i].end());
                    res &= (cols[j].find(ch) == cols[j].end());
                    res &= (box[3 * (i / 3) + j / 3].find(ch) == box[3 * (i / 3) + j / 3].end());

                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    box[3 * (i / 3) + j / 3].insert(ch); // 3 * (i/3)  != i because (i/3) is integer division, so it rounds to 0,3 and 6 only.
                }
            }
        }

        return res;
    }
};