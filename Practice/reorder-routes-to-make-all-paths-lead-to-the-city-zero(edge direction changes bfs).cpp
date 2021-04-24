class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<int>> adj(n), back(n);
        for(auto c: connections){
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        queue<int> Q;
        Q.push(0);
        visited[0] = 1;
        int res = 0;
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int curr = Q.front();
                Q.pop();
                visited[curr] = 1;
                for(auto c : adj[curr])
                    if(!visited[c]){
                        res++;
                        visited[c] = 1;
                        Q.push(c);
                    }
                for(auto c: back[curr])
                    if(!visited[c]){
                        visited[c] = 1;
                        Q.push(c);
                    }
            }
        }
        return res;
    }
};