class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto time: times){
            int x = time[0], y = time[1], w = time[2];
            graph[x].push_back({y, w});
        }
        vector<int> dis(n+1, INT_MAX);
        unordered_set<int> visited;
        queue<int> Q;
        dis[k] = 0;
        Q.push(k);
        visited.insert(k);
        
        while(!Q.empty()){
            int node = Q.front(); Q.pop();
            visited.erase(node);
            for(auto e: graph[node]){
                if(dis[node] != INT_MAX and dis[e.first] > dis[node] + e.second){
                    dis[e.first] = dis[node] + e.second;
                    if (!visited.count(e.first)) {
                        Q.push(e.first);
                        visited.insert(e.first);
                    }
                }
            }
        }
        
        int maxwait = 0;
        for (int i = 1; i <= n ; i++)
            maxwait = max(maxwait, dis[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};