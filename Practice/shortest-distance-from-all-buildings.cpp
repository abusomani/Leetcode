/*
Approach is to do BFS from each building you encounter but set destination as (target).
For first building target = 0, for second = -1 and so on.
By this way you can always ensure that final destination node is visited by all buildings.

Keep a distance array to store the minimum distance using level.

Time complexity = > O(M*N * M*N)
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

    int shortestDistance(vector<vector<int>> &grid)
    {
        int N = grid.size(), M = N ? grid[0].size() : 0;
        vector<vector<int>> distance(N, vector<int>(M, 0));

        int target = 0; // initially find the nodes with 0 value
        int minDist = INT_MAX, level;

        queue<pair<int, int>> Q;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] != 1)
                    continue;
                Q.push({i, j});
                minDist = INT_MAX;
                level = 1;
                while (!Q.empty())
                {
                    int sz = Q.size();
                    while (sz--)
                    {
                        pair<int, int> P = Q.front();
                        Q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int x = P.first + dx[dir];
                            int y = P.second + dy[dir];

                            if (isValid(x, y, N, M) and grid[x][y] == target)
                            {
                                Q.push({x, y});
                                grid[x][y]--;
                                distance[x][y] += level;
                                minDist = min(minDist, distance[x][y]);
                            }
                        }
                    }
                    level++;
                }
                target--; // for second building find the place with value target-1
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};