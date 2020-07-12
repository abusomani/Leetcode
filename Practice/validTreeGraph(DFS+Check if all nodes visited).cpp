class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        int N = edges.size();
        if (N != n - 1)
            return false;

        // if n-1 edges then the logic is not checking cycle in dfs rather
        // perform one dfs and after which all nodes must have been visited
        vector<vector<int>> graph(n);
        vector<int> visited(n, false);

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(graph, visited, 0);

        bool ret = true;
        for (int i = 0; i < n; i++)
            ret &= visited[i];

        return ret;
    }

private:
    void dfs(vector<vector<int>> &graph, vector<int> &visited, int node)
    {
        if (visited[node])
            return;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
            dfs(graph, visited, graph[node][i]);
    }
};