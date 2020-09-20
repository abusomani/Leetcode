class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    bool isValid(int x, int y, int N, int M)
    {
        return (x >= 0 and x < N and y >= 0 and y < M);
    }

public:
    void BFS(queue<pair<int, int>> &Q, int N, int M, vector<vector<int>> &V, vector<vector<int>> &vis)
    {

        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                pair<int, int> P = Q.front();
                Q.pop();
                vis[P.first][P.second] = 1;
                for (int i = 0; i < 4; i++)
                {
                    int x = P.first + dx[i], y = P.second + dy[i];
                    // surrounding should be >= than this
                    if (isValid(x, y, N, M) and !vis[x][y] and V[x][y] >= V[P.first][P.second]) 
                    {
                        Q.push({x, y});
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        vector<vector<int>> res, pac(N, vector<int>(M, 0)), atl(N, vector<int>(M, 0));
        if (N == 0 or M == 0)
            return res;
        queue<pair<int, int>> Q;
        for (int i = 0; i < M; i++)
            Q.push({0, i});
        for (int i = 0; i < N; i++)
            Q.push({i, 0});
        BFS(Q, N, M, matrix, pac);
        for (int i = 0; i < M; i++)
            Q.push({N - 1, i});
        for (int i = 0; i < N; i++)
            Q.push({i, M - 1});
        BFS(Q, N, M, matrix, atl);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (pac[i][j] and atl[i][j])
                    res.push_back({i, j});

        return res;
    }
};