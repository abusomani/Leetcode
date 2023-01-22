class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int src, int color)
    {
        if (colors[src] != 0)
            return colors[src] == color;
        colors[src] = color;
        for (auto &neighbor : graph[src])
            if (!dfs(graph, colors, neighbor, -color))
                return false;

        return true;
    }
    bool BFS(vector<vector<int>> &graph, unordered_map<int, int> &colors, int src)
    {
        colors[src] = 1;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                int present = Q.front();
                Q.pop();
                int color = colors[present];
                for (auto &neighbor : graph[present])
                {
                    if (colors.count(neighbor) and colors[neighbor] != -color)
                        return false;
                    else if (!colors.count(neighbor))
                    {
                        colors[neighbor] = -color;
                        Q.push(neighbor);
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int N = graph.size();
        // DFS
        vector<int> colors(N, 0);
        for (int i = 0; i < N; i++)
            if (colors[i] == 0 and !dfs(graph, colors, i, 1))
                return false;
        return true;

        // BFS
        bool possible = true;
        unordered_map<int, int> colors;
        for (int i = 0; i < N; i++)
        {
            if (!colors.count(i))
                possible &= BFS(graph, colors, i);
        }
        return possible;
    }
};