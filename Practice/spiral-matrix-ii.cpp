class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isValid(int i, int j, int N) {
        return i >= 0 and i <N and j >=0 and j<N;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int dir = 0;
        int x = 0, y = 0, N = n, cnt = 1;
        while(cnt <= n*n) {
            res[x][y] = cnt++;
            x += dx[dir];
            y += dy[dir];
            if(!isValid(x,y, N) or res[x][y] != 0) {
                x -= dx[dir];
                y -= dy[dir];
                dir = (dir+1)%4;
                x += dx[dir];
                y += dy[dir];
            }
        }
        return res;
    }
};