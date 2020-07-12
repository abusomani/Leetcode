class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        int N = maze.size(), M = N ? maze[0].size() : 0;
        queue<pair<int, int>> Q;
        Q.push({start[0], start[1]});
        maze[start[0]][start[1]] = -1;
        while (!Q.empty())
        {
            pair<int, int> coord = Q.front();
            Q.pop();

            if (coord.first == destination[0] and coord.second == destination[1])
                return true;

            for (int i = 0; i < 4; i++)
            {
                int x = coord.first + dx[i];
                int y = coord.second + dy[i];

                while (isValid(x, y, N, M) and maze[x][y] != 1) // either invalid or hit a wall
                    x += dx[i], y += dy[i];

                if (maze[x - dx[i]][y - dy[i]] == 0)
                {
                    maze[x - dx[i]][y - dy[i]] = -1;
                    Q.push({x - dx[i], y - dy[i]});
                }
            }
        }

        return false;
    }
};