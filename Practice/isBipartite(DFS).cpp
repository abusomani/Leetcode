class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int N = graph.size();
        vector<int> colors(N, 0); // all UNASSIGNED;
        for (int i = 0; i < N; i++)
        {
            if (colors[i] == 0 and !dfs(graph, colors, i, 1)) // while calling check for UNASSIGNED
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int src, int color)
    {
        if (colors[src] != 0)
            return colors[src] == color; // should be the color expected at the node => color

        colors[src] = color;
        for (int i = 0; i < graph[src].size(); i++)
            if (!dfs(graph, colors, graph[src][i], -color)) // negation of color
                return false;

        return true;
    }
};