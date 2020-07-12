//https : //assets.leetcode.com/users/votrubac/image_1572844905.png
class Solution
{
public:
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, int &diameter)
    {
        visited[src] = true;
        auto max_depth = 0;
        for (auto nxt : graph[src])
        {
            if (!visited[nxt])
            {
                auto depth = dfs(graph, visited, nxt, diameter);
                diameter = max(diameter, depth + max_depth); // compute maximum at each step in diamter
                max_depth = max(max_depth, depth);           // max depth till here
            }
        }

        return (src == 0) ? diameter : max_depth + 1;
    }

    int treeDiameter(vector<vector<int>> &edges)
    {
        int N = edges.size(), diameter = 0;
        vector<bool> visited(N + 1, false);
        vector<vector<int>> graph(N + 1);

        for (int i = 0; i < N; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(graph, visited, 0, diameter);
    }
};