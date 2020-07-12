class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<pair<int, int>, int>> Q;
        int N = rooms.size(), M = N ? rooms[0].size() : 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (rooms[i][j] == 0)
                    Q.push({{i, j}, 0});

        while (!Q.empty())
        {
            pair<pair<int, int>, int> pr = Q.front();
            Q.pop();
            pair<int, int> coord = pr.first;
            int dist = pr.second;

            for (int k = 0; k < 4; k++)
            {
                int x = coord.first + dx[k];
                int y = coord.second + dy[k];
                if (isValid(x, y, N, M) and rooms[x][y] == 2147483647) // not a wall or obstacle
                {
                    rooms[x][y] = min(rooms[x][y], dist + 1);
                    Q.push({{x, y}, rooms[x][y]});
                }
            }
        }
    }
};