class Solution {
private:
    unordered_set<int> visited;
    void dfs(int src, vector<vector<int>> &G){
        visited.insert(src);
        for(int i=0; i<G.size(); i++)
            if(i != src and !visited.count(i) and G[src][i])
                dfs(i, G);
    }
public:
    int findCircleNum(vector<vector<int>>& G) {
        int N = G.size();
        int res = 0;
        for(int i=0; i<N; i++)
            if(!visited.count(i))
                res++, dfs(i, G);
        return res;
    }
};