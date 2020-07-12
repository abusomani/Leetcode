class Solution
{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        vector<int> result;
        if (N == 0 or M == 0)
            return result;
        int x = 0, y = 0, idx = 0;

        while (result.size() < N * M)
        {
            result.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            x += dx[idx];
            y += dy[idx];
            if (!isValid(x, y, N, M) or matrix[x][y] == INT_MIN)
            { // not valid or already visited
                // then change direction
                x -= dx[idx];
                y -= dy[idx];
                idx = (idx + 1) % 4;
                x += dx[idx];
                y += dy[idx];
            }
        }
        return result;
    }
};