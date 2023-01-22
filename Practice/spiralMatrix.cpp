class Solution
{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    string coordinateToString(int x, int y)
    {
        return to_string(x) + "#" + to_string(y);
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if (N == 0 or M == 0)
            return vector<int>();
        unordered_set<string> visited;
        vector<int> result;
        int dir = 0, i = 0, j = 0, cnt = 0;
        while (cnt < M * N)
        {
            result.push_back(matrix[i][j]);
            visited.insert(coordinateToString(i, j));
            matrix[i][j] = INT_MAX;
            cnt++;
            i += dx[dir];
            j += dy[dir];
            if (!isValid(i, j, N, M) or visited.count(coordinateToString(i, j)))
            {
                i -= dx[dir];
                j -= dy[dir];
                dir = (dir + 1) % 4;
                i += dx[dir];
                j += dy[dir];
            }
        }

        return result;
    }
};