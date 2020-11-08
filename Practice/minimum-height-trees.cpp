#define pb push_back
class Solution {
private:
    int N;
    vector<int> bfs(vector<vector<int>> &graph, int src) {
        vector<int> parent(N, INT_MAX);
        queue<int> Q;
        Q.push(src);
        parent[src] = -1;
        int last = -1;
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                int node = Q.front();
                last = node;
                Q.pop();
                for(auto &neighbor: graph[node]) {
                    if(parent[neighbor] == INT_MAX) {
                        Q.push(neighbor);
                        parent[neighbor] = node;
                    }
                }
            }
        }
        vector<int> path;
        while(last != -1) {
            path.push_back(last);
            last = parent[last];
        }
        return path;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> graph(n);
        for(auto &edge: edges) {
            int a = edge[0], b = edge[1];
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vector<int> first = bfs(graph, 0);
        vector<int> longest = bfs(graph, first[0]);
        int sz = longest.size();
        vector<int> res;
        res.push_back(longest[(sz-1)/2]);
        if(!(sz&1))
            res.push_back(longest[sz/2]);
        return res;
    }
};