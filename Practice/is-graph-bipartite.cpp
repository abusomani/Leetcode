class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<int> &colors, int color)
    {
        if (colors[src] != 0)
            return colors[src] == color;

        colors[src] = color;
        for (auto &neighbor : graph[src])
            if (!dfs(neighbor, graph, colors, -color))
                return false;

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int N = graph.size();
        vector<int> colors(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (colors[i] == 0 and !dfs(i, graph, colors, 1))
                return false;
        }
        return true;
    }
};