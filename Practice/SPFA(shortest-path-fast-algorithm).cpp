const int INF = 1e9+7;
vector<vector<pair<int,int>>> adj;

bool SPFANegativeCycleExists(int s){
    int N = adj.size(); // vertices
    vector<int> dist(N, INF);
    vector<int> cnt(N, 0);
    vector<bool> inQueue(N, false);
    queue<int> Q;

    dist[s] = 0;
    Q.push(s);
    inQueue[s] = true;
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        inQueue[node] = false;
        for(auto edge: adj[node]){
            if(dist[edge.first] > dist[node] + edge.second){
                dist[edge.first] = dist[node] + edge.second;
                if(!inQueue[edge.first]){
                    Q.push(edge.first);
                    inQueue[edge.first] = true;
                    cnt[edge.first]++;
                    if(cnt[edge.first] > N){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}