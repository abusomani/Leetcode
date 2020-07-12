class Solution
{
private:
    int N;
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    int bfs(int src, int dest, int K)
    {
        int ans = INT_MAX;
        queue<pair<int, int>> Q;
        Q.push({src, 0});
        int level = 0;
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                pair<int, int> node = Q.front();
                Q.pop();
                if (node.first == dest)
                    ans = min(ans, node.second);
                for (auto &next : graph[node.first])
                {
                    if (node.second + next.second > ans) // PRUNING
                        continue;
                    Q.push({next.first, node.second + next.second});
                }
            }
            level++;
            if (level > K)
                break;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dest, int K)
    {
        N = n;
        for (auto &edge : flights)
            graph[edge[0]].push_back({edge[1], edge[2]});

        return bfs(src, dest, K + 1);
    }
};