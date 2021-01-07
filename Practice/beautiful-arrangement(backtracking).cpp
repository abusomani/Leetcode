class Solution {
public:
    int dfs(vector<int> &visited, int idx, int N) {
        if(idx > N)
            return 1; // valid arrangement
        else {
            int sm = 0;
            for(int num=1; num<=N; num++) {
                if(visited[num])continue;
                if(idx%num == 0 or num%idx == 0) {
                    visited[num] = true;
                    sm += dfs(visited, idx+1, N);
                    visited[num] = false;
                }
            }
            return sm;
        }
    }
    int countArrangement(int N) {
        vector<int> visited(N+1, false);
        return dfs(visited, 1, N);
    }
};