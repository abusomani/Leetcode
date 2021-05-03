class Solution {
private:
    vector<vector<int>> G;
    unordered_set<int> visited;
    void dfs(int src){
        visited.insert(src);
        for(auto e: G[src])
            if(!visited.count(e))
                dfs(e);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        G.resize(n);
        for(auto edge: edges)
        {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for(int i=0; i<n; i++)
            if(!visited.count(i))
                dfs(i), res++;
        return res;
    }
};