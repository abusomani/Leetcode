// MULTI SOURCE BFS
class Solution {
private:
    int N, M, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    bool isValid(int x, int y) {
        return (x >= 0 and x <N and y >= 0 and y < M);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        N = matrix.size(), M = matrix[0].size();
        vector<vector<int>> dp(N, vector<int>(M, -1));
        queue<pair<int,int>> Q;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(matrix[i][j] == 0)
                    Q.push({i, j}), dp[i][j] = 0;
        
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                pair<int,int> P = Q.front();
                Q.pop();
                
                for(int i=0; i<4; i++) {
                    int x = P.first + dx[i], y = P.second + dy[i];
                    if(isValid(x,y) and matrix[x][y] == 1 and dp[x][y] == -1) {
                        dp[x][y] = dp[P.first][P.second] + 1;
                        Q.push({x,y});
                    }
                }
                
            }
        }
        
        return dp;
    }
};