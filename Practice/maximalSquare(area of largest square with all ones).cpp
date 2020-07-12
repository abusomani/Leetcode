//Time complexity = O((mn)^2)
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
                if (matrix[i][j] == '1') // top-left is fixed
                {
                    int sqLen = 1;
                    bool valid = true;
                    while (i + sqLen < N and j + sqLen < M and valid) // no repeated checking
                    {
                        for (int k = j; k <= j + sqLen; k++) // fix next row and check columns with length sqLen
                            if (matrix[i + sqLen][k] == '0')
                            {
                                valid = false;
                                break;
                            }

                        for (int k = i; k <= i + sqLen; k++) // fix next col and check rows with length sqLen
                            if (matrix[k][j + sqLen] == '0')
                            {
                                valid = false;
                                break;
                            }
                        if (valid)
                            sqLen++;
                    }
                    ans = max(ans, sqLen * sqLen);
                }
            }
        }

        return ans;
    }
};