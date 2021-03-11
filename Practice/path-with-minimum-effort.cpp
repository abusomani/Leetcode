int MAX_MUL = 105; // As max 100 rows and colum.
// Every cell can be identified by i * MAX_MUL + j
class Solution {
private:
    int DX[4] = {0,0,1,-1};
    int DY[4] = {1,-1,0,0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int N = heights.size(), M = heights[0].size();
        vector<vector<int>> dp(N, vector<int>(M, INT_MAX));
        // Min heap, effort here, coordinates
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
        dp[0][0] = 0; // Base case
        PQ.push({0,0}); // 0 effort required at 0th position
        while(!PQ.empty()) {
            auto P = PQ.top();
            PQ.pop();
            int effort = P.first , i = P.second / MAX_MUL, j = P.second % MAX_MUL;
            if(i == N-1 and j == M-1)break;
            for(int k=0; k<4; k++) {
                int x = i + DX[k] , y = j + DY[k];
                if(x < 0 or x >= N or y < 0 or y >= M)continue;
                // for the next node, the dp would be max of previous node or the absolute difference
                int newEffort = max(dp[i][j], abs(heights[i][j] - heights[x][y]));
                if(newEffort < dp[x][y]) // relax the node 
                {
                    dp[x][y] = newEffort;
                    PQ.push({newEffort, x * MAX_MUL+y});
                }
            }
        }
        return dp[N-1][M-1];
    }
};