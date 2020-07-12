/*
Time complexity => (M*N)
Simply do a multi source BFS with the grid itself helping in marking visited.
Only push into queue if the grid[i][j] == 0, for others the grid[i][j] represents the shortest distance from any node
max over all such nodes will be the answer.
*/
class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int x, int y, int N, int M)
    {
        return (x >= 0 and x < N and y >= 0 and y < M);
    }
    string coordToString(int x, int y)
    {
        return to_string(x) + "#" + to_string(y);
    }
    int maxDistance(vector<vector<int>> &grid)
    {
        int N = grid.size(), M = N ? grid[0].size() : 0;
        if (N == 0 or M == 0)
            return -1;

        int ans = 0;
        bool isWaterFound = false;
        queue<pair<int, int>> Q;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j] == 1)
                    Q.push({i, j});

        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                pair<int, int> P = Q.front();
                Q.pop();

                int x = P.first;
                int y = P.second;

                for (int dir = 0; dir < 4; dir++)
                {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    if (!isValid(newX, newY, N, M))
                        continue;

                    if (!grid[newX][newY])
                    {
                        isWaterFound = true;
                        grid[newX][newY] = grid[x][y] + abs(newX - x) + abs(newY - y);
                        ans = max(ans, grid[newX][newY]);
                        Q.push({newX, newY});
                    }
                }
            }
        }

        return ans - 1;
    }
};