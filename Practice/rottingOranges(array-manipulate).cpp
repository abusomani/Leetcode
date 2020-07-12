class Solution
{
public:
    bool isValid(int i, int j, int N, int M, vector<vector<int>> &grid)
    {
        if (i >= 0 and i < N and j >= 0 and j < M and grid[i][j] == 1) // if its fresh and we are going to push it, then make it empty so that redundant push in queue are saved
        {
            grid[i][j] = 2;
            return true;
        }
        return false;
    }
    int BFS(queue<pair<int, int>> &Q, int fresh, int N, int M, vector<vector<int>> &grid)
    {
        int mins = 0;
        while (!Q.empty())
        {
            pair<int, int> P = Q.front();
            Q.pop();

            if (Q.empty())
                break;
            if (P.first == -1 and P.second == -1)
            {
                mins++;
                Q.push({-1, -1});
                continue;
            }
            int i = P.first, j = P.second;
            grid[i][j] = 0;
            if (isValid(i + 1, j, N, M, grid))
                fresh--, Q.push({i + 1, j});
            if (isValid(i - 1, j, N, M, grid))
                fresh--, Q.push({i - 1, j});
            if (isValid(i, j + 1, N, M, grid))
                fresh--, Q.push({i, j + 1});
            if (isValid(i, j - 1, N, M, grid))
                fresh--, Q.push({i, j - 1});
        }

        return fresh == 0 ? mins : -1;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int N = grid.size(), M = N ? grid[0].size() : 0;

        int fresh = 0;
        queue<pair<int, int>> Q;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 2)
                    Q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }

        Q.push({-1, -1});
        return BFS(Q, fresh, N, M, grid);
    }
};