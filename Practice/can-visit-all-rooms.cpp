class Solution {
private:
    void dfs(vector<vector<int>> &rooms, int src, unordered_set<int> &visited){
        visited.insert(src);
        for(auto &n: rooms[src]) {
            if(!visited.count(n))
                dfs(rooms, n, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        unordered_set<int> visited;
        dfs(rooms, 0,visited);        
        return (int)visited.size() == N;
    }
};