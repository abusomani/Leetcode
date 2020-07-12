class Solution
{
public:
    pair<int, int> BFS(vector<vector<int>> &graph, int src)
    {
        vector<bool> visited(graph.size() + 1, false);
        pair<int, int> P;
        int mx = 0;
        queue<pair<int, int>> Q;
        Q.push({src, 0});
        while (!Q.empty())
        {
            pair<int, int> node = Q.front();
            Q.pop();
            visited[node.first] = true;

            if (node.second > mx)
            {
                mx = node.second;
                P = node;
            }

            for (int i = 0; i < graph[node.first].size(); i++)
            {
                int nxt = graph[node.first][i];
                if (!visited[nxt])
                    Q.push({nxt, node.second + 1});
            }
        }

        return P;
    }

    int treeDiameter(vector<vector<int>> &edges)
    {
        int N = edges.size();
        vector<vector<int>> graph(N + 1);

        for (int i = 0; i < N; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        pair<int, int> farthest = BFS(graph, 0);
        return BFS(graph, farthest.first).second;
    }
};