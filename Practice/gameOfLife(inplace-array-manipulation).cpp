class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int N = board.size(), M = N ? board[0].size() : 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int count = 0;

                for (int I = max(i - 1, 0); I < min(i + 2, N); I++)
                    for (int J = max(j - 1, 0); J < min(j + 2, M); J++)
                        count += board[I][J] & 1; // counting all neighbours of <i,j> including itself

                if (count == 3 || count - board[i][j] == 3) //either two neighbours or three
                    board[i][j] |= 2;
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] >>= 1;
    }
};