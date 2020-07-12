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
        vector<bool> visited(n, false);

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if (hasCycle(graph, 0, -1, visited))
            return false; // if there is a cycle straight false

        // else there might be forests or disjoint sets
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;

        return true;
    }

private:
    bool hasCycle(vector<vector<int>> &neighbors, int kid, int parent, vector<bool> &visited)
    {
        if (visited[kid])
            return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};