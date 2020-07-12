class Solution
{
private:
    pair<int, int> best; // length, node
    vector<vector<int>> w;

public:
    void dfs(int s, int par, int len)
    {
        best = max(best, {len, s});
        for (auto a : w[s])
            if (a != par) // cycle
                dfs(a, s, len + 1);
    }
    int treeDiameter(vector<vector<int>> &edges)
    {
        int N = edges.size() + 1;
        w.clear();
        w.resize(N);

        for (auto edge : edges)
        {
            w[edge[0]].push_back(edge[1]);
            w[edge[1]].push_back(edge[0]);
        }

        best = {-1, -1};
        dfs(0, -1, 0);
        int from = best.second;
        best = {-1, -1};
        dfs(from, -1, 0);
        return best.first;
    }
};