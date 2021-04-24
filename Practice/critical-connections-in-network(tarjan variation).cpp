class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int,int> T;
    int timer = 1;
    int dfs(vector<vector<int>> &G, int src, int parent){
        //if visited, return visited timestamp
        if(T[src] != 0)
            return T[src];
        T[src] = timer++; // assign time
        int timestamp = INT_MAX;
        for(auto c: G[src]){
            if(c == parent)continue;
            timestamp = min(timestamp, dfs(G, c, src));
        }
        // not in cycle
        if(timestamp >= T[src] and parent != -1){
            res.push_back({src, parent});
        }
        // minimum of neighbors or itself
        return min(timestamp, T[src]);
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G(n);
        for(auto edge: connections){
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        dfs(G, 0, -1);
        return res;
    }
};