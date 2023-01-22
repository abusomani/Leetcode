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
        int N = rooms.size(), M = N ? rooms[0].size() : 0;
        if (N == 0 or M == 0)
            return;
        queue<pair<int, int>> Q;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (rooms[i][j] == 0)
                    Q.push({i, j});

        int level = 1;
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                pair<int, int> curr = Q.front();
                Q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int newX = curr.first + dx[i];
                    int newY = curr.second + dy[i];
                    if (isValid(newX, newY, N, M) and rooms[newX][newY] == INT_MAX)
                    {
                        rooms[newX][newY] = level;
                        Q.push({newX, newY});
                    }
                }
            }
            level++;
        }
    }
};