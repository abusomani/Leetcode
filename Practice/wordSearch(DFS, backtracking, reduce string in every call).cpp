class Solution
{
public:
    bool adjSearch(vector<vector<char>> &board, string word, int i, int j)
    {
        if (!word.size())
            return true; // all characters match
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or word[0] != board[i][j])
            return false;

        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool result = adjSearch(board, s, i + 1, j) or
                      adjSearch(board, s, i - 1, j) or
                      adjSearch(board, s, i, j + 1) or
                      adjSearch(board, s, i, j - 1);
        board[i][j] = c;
        return result;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (adjSearch(board, word, i, j))
                    return true;

        return false;
    }
};