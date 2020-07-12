class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int N = graph.size();
        vector<int> colors(N, -1); // all white;
        bool ans = true;
        for (int i = 0; i < N; i++)
        {
            if (colors[i] == -1)
                ans &= BFS(graph, colors, i, 0);
        }
        return ans;
    }

    bool BFS(vector<vector<int>> &graph, vector<int> &colors, int src, int color)
    {
        queue<pair<int, int>> Q;
        Q.push({src, color});
        while (!Q.empty())
        {
            pair<int, int> P = Q.front();
            Q.pop();
            colors[P.first] = P.second;

            for (int i = 0; i < graph[P.first].size(); i++)
            {
                int nextIdx = graph[P.first][i];
                if (colors[nextIdx] == P.second)
                {
                    return false;
                }
                if (colors[nextIdx] == -1)
                    Q.push({nextIdx, !P.second});
            }
        }
        return true;
    }
};