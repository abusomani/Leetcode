class Solution
{
private:
    int N;
    int ans = INT_MAX;

public:
    int dx[8] = {0, 1, 1, 0, 1, -1, -1};
    int dy[8] = {1, 0, 1, -1, -1, 1, -1};
    bool isValid(int x, int y)
    {
        return x >= 0 and x < N and y >= 0 and y < N;
    }
    int bfs(int x, int y, vector<vector<int>> &grid)
    {
        int level = 1;
        set<pair<int, int>> visited;
        queue<pair<int, int>> Q;
        Q.push({x, y});
        visited.insert({x, y});
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                auto P = Q.front();
                Q.pop();

                if (P.first == N - 1 and P.second == N - 1)
                    return level;

                for (int i = 0; i < 8; i++)
                {
                    int newX = P.first + dx[i], newY = P.second + dy[i];
                    if (newX == N - 1 and newY == N - 1 and grid[newX][newY] == 0)
                        return level + 1;

                    if (isValid(newX, newY) and grid[newX][newY] == 0 and !visited.count({newX, newY}))
                    {
                        visited.insert({newX, newY});
                        Q.push({newX, newY});
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        N = grid.size();
        if (grid[0][0] == 1)
            return -1;
        return bfs(0, 0, grid);
    }
};