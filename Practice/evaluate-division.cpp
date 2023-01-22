class Solution
{
private:
    map<string, map<string, double>> graph;

public:
    double dfs(string src, string dest, unordered_set<string> &visited)
    {
        if (graph[src].count(dest))
            return graph[src][dest];

        visited.insert(src);
        double product = -1.0;
        for (auto &neighbor : graph[src])
        {
            string next = neighbor.first;
            double value = neighbor.second;
            if (visited.count(next))
                continue;
            double product = dfs(next, dest, visited);
            if (product != -1.0)
                return product * value;
        }
        return product;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int N = equations.size();
        for (int i = 0; i < N; i++)
        {
            string x = equations[i][0];
            string y = equations[i][1];
            double value = values[i];
            graph[x][y] = value;
            graph[y][x] = 1 / value;
        }
        int Q = queries.size();
        vector<double> res(Q, -1.0);
        for (int i = 0; i < Q; i++)
        {
            unordered_set<string> visited;
            string src = queries[i][0], dest = queries[i][1];
            if (!graph.count(src) or !graph.count(dest))
                continue;
            if (src == dest)
                res[i] = 1.0;
            else
                res[i] = dfs(src, dest, visited);
        }
        return res;
    }
};