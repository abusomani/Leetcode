class Solution
{
private:
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    void dfs(int src, int dest, int K, int cost, int &ans)
    {
        if (K < 0)
            return;
        if (src == dest)
        {
            ans = cost;
            return;
        }
        for (auto &neighbor : graph[src])
        {
            if (cost + neighbor.second > ans) // PRUNING
                continue;
            dfs(neighbor.first, dest, K - 1, cost + neighbor.second, ans);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        for (auto &edge : flights)
            graph[edge[0]].push_back({edge[1], edge[2]});

        int res = INT_MAX;
        dfs(src, dst, K + 1, 0, res);
        return res == INT_MAX ? -1 : res;
    }
};