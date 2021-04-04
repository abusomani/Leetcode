class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> G(N+1);
        vector<int> Indegree(N+1, 0);
        for(auto edge: relations)
        {
            G[edge[0]].push_back(edge[1]); // a->b
            Indegree[edge[1]]++; // indegree of b++
        }
        queue<int> Q;
        for(int i=1; i<=N; i++)
            if(Indegree[i] == 0)
                Q.push(i);
        unordered_set<int> visited;
        int level = 0;
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int node = Q.front();
                Q.pop();
                visited.insert(node);
                for(auto neighbor: G[node]) {
                    if(visited.count(neighbor))continue;
                    if(--Indegree[neighbor] == 0)
                        Q.push(neighbor), visited.insert(neighbor);
                }
            }
            level++;
        }
        return visited.size() == N ? level : -1;
    }
};