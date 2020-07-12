class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if (N == 0 or M == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] == '1')
                {
                    //len can go from 1 to min(N-i, M-j)
                    bool valid = true;
                    for (int len = 1; len <= min(N - i, M - j) and valid; len++)
                    {
                        for (int x = i; x <= i + len - 1; x++) // repeated checking
                        {
                            for (int y = j; y <= j + len - 1; y++)
                            {
                                if (matrix[x][y] == '0')
                                {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        if (valid)
                            ans = max(ans, len * len);
                    }
                }
            }
        }

        return ans;
    }
};