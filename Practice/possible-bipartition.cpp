class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<int> &colors, int color)
    {
        // if visited, expected color should match
        if (colors[src] != 0)
            return colors[src] == color;

        colors[src] = color;
        for (auto &child : graph[src])
            if (!dfs(child, graph, colors, -color))
                return false;

        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N + 1);
        for (auto &dislike : dislikes)
        {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        vector<int> colors(N + 1, 0);
        for (int i = 1; i <= N; i++)
            if (colors[i] == 0 and !dfs(i, graph, colors, 1))
                return false;

        return true;
    }
};